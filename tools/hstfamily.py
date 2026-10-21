#!/usr/bin/env python3
"""Compiler-family predictor: is an unmatched function Metrowerks game code or Sony psp-gcc SDK code?

    python tools/hstfamily.py evaluate [--folds 5]      cross-validated accuracy on the functions whose profile is known
    python tools/hstfamily.py predict [--out try/family-predictions.json]    p(Metrowerks) for every unmatched function

The campaign ledger knows the compiler only for functions that already have a source (5,009 + 701 of EBOOT.BIN's
9,804 are resolved; the other 4,094 are not). A public-first queue wants the Metrowerks ones first: the Sony SDK
reconstructions are not published (hstpublish.EXCLUDED_CLASSES), and mwccpsp code is the part of the game the project
can ship. The predictor labels every function that has a source in src/ by its header profile (`cc=gcc...` is psp-gcc,
no `cc=` or `cc=mwcc219` is Metrowerks) and learns from the function's code words alone:

  * the prologue (frame size multiple of 16 or not, where `ra` is saved relative to the frame top),
  * register habits (temporaries t0-t9, `at` as a compare destination, v1),
  * branch style (branch-likely forms, `j` versus `b`, nops, multiple `jr ra`),
  * instruction idioms (movn/movz, `break`, seb/seh versus sll+sra, `or` versus `addu` for move, VFPU),
  * where the function sits (SDK objects cluster below 0x88000) and what its neighbours in the module are.

Model: logistic regression (pure Python), features standardised on the training part. `evaluate` reports the accuracy
of three feature sets (code only; plus address; plus neighbours) with folds grouped by the masked code signature of
tools/hstclone.py, so twins and clones (same code apart from addresses) never sit in both the training and the
test part. Neighbour labels are those of the OTHER known functions around a function, which is what exists for an
unmatched function in practice.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import math
import random
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstclone as C
import hstmatch as M

ROOT = M.ROOT
MODULES = ("EBOOT.BIN", "hstp_trans_main.prx")
T_REGS = set(range(8, 16)) | {24, 25}
AT = 1


def words_of(data: bytes) -> list[int]:
    return [int.from_bytes(data[i:i + 4], "little") for i in range(0, len(data) - len(data) % 4, 4)]


def operands(w: int) -> list[int]:
    """The general registers an instruction names (rs, rt, rd for the common formats; none for j/jal)."""
    op = w >> 26
    rs, rt, rd = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
    if op == 0:
        return [rs, rt, rd]
    if op in (2, 3, 0x11, 0x12, 0x13, 0x18, 0x19, 0x1a, 0x1b, 0x32, 0x36, 0x3a, 0x3e, 0x34, 0x35, 0x37, 0x3c, 0x3d, 0x3f):
        return [] if op in (2, 3, 0x11, 0x12, 0x13, 0x18, 0x19, 0x1a, 0x1b, 0x34, 0x35, 0x37, 0x3c, 0x3d, 0x3f) else [rs]
    if op == 1:
        return [rs]
    return [rs, rt]


def feature_names() -> list[str]:
    return list(FEATURES)


FEATURES = [
    "log_size", "has_frame", "frame_mult16", "frame_mult8_only", "ra_saved", "ra_at_top", "first_store_is_ra",
    "t_rate", "at_rate", "v1_rate", "slt_at", "slt_not_at", "branch_rate", "likely_rate", "j_rate", "b_rate",
    "jal_rate", "nop_rate", "jr_ra_count", "movn_movz", "break_any", "seb_seh", "sll_sra_pairs", "move_or", "move_addu",
    "fpu_rate", "bc1_likely", "vfpu", "mult_div", "lui_rate", "ext_ins", "size_mod16",
    "addr_low", "addr_vlow",
    "prev_gcc", "prev_mw", "next_gcc", "next_mw", "near_gcc_frac",
]
CODE_ONLY = FEATURES[:32]
WITH_ADDRESS = FEATURES[:34]


def code_features(ws: list[int]) -> dict[str, float]:
    n = max(len(ws), 1)
    f = dict.fromkeys(FEATURES, 0.0)
    f["log_size"] = math.log2(n)
    f["size_mod16"] = float((4 * n) % 16 == 0)
    first = ws[0] if ws else 0
    frame = 0
    if first >> 16 == 0x27BD and first & 0x8000:
        frame = 0x10000 - (first & 0xFFFF)
    f["has_frame"] = float(frame > 0)
    f["frame_mult16"] = float(frame > 0 and frame % 16 == 0)
    f["frame_mult8_only"] = float(frame > 0 and frame % 16 != 0)
    stores = [w for w in ws[:24] if w >> 26 == 0x2B and (w >> 21) & 31 == 29]       # sw rt, off(sp)
    ra_store = next((w for w in stores if (w >> 16) & 31 == 31), None)
    if ra_store is not None:
        f["ra_saved"] = 1.0
        f["ra_at_top"] = float(frame > 0 and (ra_store & 0xFFFF) == frame - 4)
        f["first_store_is_ra"] = float(stores[0] == ra_store)
    t = at = v1 = sa = sn = br = lk = j = b = jal = nop = jr = mm = brk = sebh = pairs = mo = ma = fpu = bcl = vf = md = lui = ei = 0
    for i, w in enumerate(ws):
        op, funct = w >> 26, w & 63
        regs = operands(w)
        t += any(r in T_REGS for r in regs)
        at += AT in regs
        v1 += 3 in regs
        rs, rt, rd = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        if (op == 0 and funct in (0x2A, 0x2B) and rd == AT) or (op in (0x0A, 0x0B) and rt == AT):
            sa += 1
        elif (op == 0 and funct in (0x2A, 0x2B)) or op in (0x0A, 0x0B):
            sn += 1
        is_branch = op in (4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17) or op == 1 or (op == 0x11 and rs == 8)
        br += is_branch
        lk += op in (0x14, 0x15, 0x16, 0x17) or (op == 1 and rt in (2, 3, 0x12, 0x13)) or (op == 0x11 and rs == 8 and rt in (2, 3))
        bcl += op == 0x11 and rs == 8 and rt in (2, 3)
        j += op == 2
        b += op == 4 and rs == 0 and rt == 0
        jal += op == 3
        nop += w == 0
        jr += op == 0 and funct == 8 and rs == 31
        mm += op == 0 and funct in (0x0A, 0x0B)
        brk += op == 0 and funct == 0x0D
        sebh += op == 0x1F and funct == 0x20
        ei += op == 0x1F and funct in (0, 4)
        mo += op == 0 and funct == 0x25 and rt == 0
        ma += op == 0 and funct == 0x21 and rt == 0
        fpu += op in (0x11, 0x31, 0x39)
        vf += op in (0x18, 0x19, 0x1A, 0x1B, 0x32, 0x36, 0x3A, 0x3E, 0x34, 0x35, 0x37, 0x3C, 0x3D, 0x3F)
        md += op == 0 and funct in (0x18, 0x19, 0x1A, 0x1B, 0x10, 0x12)
        lui += op == 0x0F
        if i + 1 < len(ws) and op == 0 and funct == 0 and ((w >> 6) & 31) == 16 and ws[i + 1] & 0xFC00003F == 3 and ((ws[i + 1] >> 6) & 31) == 16:
            pairs += 1
    f.update(t_rate=t / n, at_rate=at / n, v1_rate=v1 / n, slt_at=sa / n, slt_not_at=sn / n, branch_rate=br / n,
             likely_rate=lk / n, j_rate=j / n, b_rate=b / n, jal_rate=jal / n, nop_rate=nop / n, jr_ra_count=float(min(jr, 4)),
             movn_movz=float(mm > 0), break_any=float(brk > 0), seb_seh=float(sebh > 0), sll_sra_pairs=float(min(pairs, 4)),
             move_or=mo / n, move_addu=ma / n, fpu_rate=fpu / n, bc1_likely=float(bcl > 0), vfpu=float(vf > 0), mult_div=float(md > 0),
             lui_rate=lui / n, ext_ins=float(ei > 0))
    return f


def address_features(start: int) -> dict[str, float]:
    return {"addr_low": float(start < 0x88000), "addr_vlow": float(start < 0x40000)}


# --------------------------------------------------------------------------------------------------------------

class Fn:
    __slots__ = ("module", "start", "end", "label", "feat", "group", "index")

    def __init__(self, module, start, end, label, feat, group):
        self.module, self.start, self.end, self.label, self.feat, self.group = module, start, end, label, feat, group
        self.index = 0


def load_functions() -> dict[str, list[Fn]]:
    """Every reviewed function of both game modules in address order; label 1 = Metrowerks, 0 = psp-gcc, None = unknown."""
    led = json.loads((M.CAMPAIGN / "ledger" / "campaign.json").read_text(encoding="utf-8-sig"))
    labels: dict[tuple[str, int], int] = {}
    for p in sorted((ROOT / "src").rglob("*")):
        if p.suffix in (".c", ".cpp") and p.parent.name in ("eboot", "sharing_main"):
            h = M.parse_header(p)
            labels[(h["module"], h["start"])] = 0 if h.get("cc", "mwcc219").startswith("gcc") else 1
    cache: dict = {}
    out: dict[str, list[Fn]] = {}
    for mod in led["modules"]:
        if mod["name"] not in MODULES:
            continue
        data, seg = M.module_bytes(cache, mod["name"])
        fns = []
        for f in sorted(mod["functions"], key=lambda x: x["start"]):
            off = seg["file_offset"] + f["start"] - seg["start"]
            raw = data[off:off + f["end"] - f["start"]]
            ws = words_of(raw)
            feat = code_features(ws)
            feat.update(address_features(f["start"]))
            sig = C.analyse(ws)[0]
            group = hashlib.md5(repr(sig).encode()).hexdigest()
            fns.append(Fn(mod["name"], f["start"], f["end"], labels.get((mod["name"], f["start"])), feat, group))
        for i, fn in enumerate(fns):
            fn.index = i
        out[mod["name"]] = fns
    return out


def add_neighbours(fns: list[Fn], hidden: set[int] | None = None, window: int = 8) -> None:
    """Fill the neighbour features of every function from the labels of the OTHER known functions around it."""
    hidden = hidden or set()
    known = [(fn.index, fn.label) for fn in fns if fn.label is not None and fn.index not in hidden]
    pos = [k[0] for k in known]
    import bisect
    for fn in fns:
        k = bisect.bisect_left(pos, fn.index)
        before = [(i, lab) for i, lab in known[max(0, k - window):k] if i != fn.index]
        after = [(i, lab) for i, lab in known[k:k + window + 1] if i != fn.index][:window]
        f = fn.feat
        f["prev_gcc"] = f["prev_mw"] = f["next_gcc"] = f["next_mw"] = 0.0
        if before:
            i, lab = before[-1]
            near = 1.0 / (1 + fn.index - i)
            f["prev_gcc" if lab == 0 else "prev_mw"] = near
        if after:
            i, lab = after[0]
            near = 1.0 / (1 + i - fn.index)
            f["next_gcc" if lab == 0 else "next_mw"] = near
        around = before + after
        f["near_gcc_frac"] = (sum(1 for _i, lab in around if lab == 0) / len(around)) if around else 0.5


# --------------------------------------------------------------------------------------------------------------

class Logistic:
    def __init__(self, names: list[str], balanced: bool = True):
        self.names = names
        self.balanced = balanced
        self.mean = [0.0] * len(names)
        self.std = [1.0] * len(names)
        self.w = [0.0] * len(names)
        self.b = 0.0

    def vec(self, feat: dict) -> list[float]:
        return [(feat[n] - m) / s for n, m, s in zip(self.names, self.mean, self.std)]

    def fit(self, rows: list[Fn], epochs: int = 40, lr: float = 0.05, l2: float = 1e-3, seed: int = 1) -> None:
        cols = [[r.feat[n] for r in rows] for n in self.names]
        self.mean = [sum(c) / len(c) for c in cols]
        self.std = [max(math.sqrt(sum((x - m) ** 2 for x in c) / len(c)), 1e-6) for c, m in zip(cols, self.mean)]
        xs = [self.vec(r.feat) for r in rows]
        ys = [r.label for r in rows]
        rng = random.Random(seed)
        order = list(range(len(rows)))
        n_pos = sum(ys)
        n_neg = len(ys) - n_pos
        pos_w, neg_w = (0.5 * len(ys) / max(n_pos, 1), 0.5 * len(ys) / max(n_neg, 1)) if self.balanced else (1.0, 1.0)
        for ep in range(epochs):
            rng.shuffle(order)
            step = lr / (1 + 0.1 * ep)
            for i in order:
                z = self.b + sum(w * x for w, x in zip(self.w, xs[i]))
                p = 1 / (1 + math.exp(-max(min(z, 30), -30)))
                g = (p - ys[i]) * (pos_w if ys[i] == 1 else neg_w)
                for k in range(len(self.w)):
                    self.w[k] -= step * (g * xs[i][k] + l2 * self.w[k])
                self.b -= step * g

    def prob(self, feat: dict) -> float:
        z = self.b + sum(w * x for w, x in zip(self.w, self.vec(feat)))
        return 1 / (1 + math.exp(-max(min(z, 30), -30)))


def auc(pairs: list[tuple[int, float]]) -> float:
    """Area under the ROC curve (rank statistic): the chance that a Metrowerks function scores above a psp-gcc one."""
    pos = sorted(p for y, p in pairs if y == 1)
    neg = [p for y, p in pairs if y == 0]
    if not pos or not neg:
        return float("nan")
    import bisect
    wins = sum(bisect.bisect_left(pos, q) for q in neg)          # positives below a negative
    return round(1 - wins / (len(pos) * len(neg)), 4)


def metrics(pairs: list[tuple[int, float]], threshold: float = 0.5) -> dict:
    tp = sum(1 for y, p in pairs if y == 1 and p >= threshold)
    fn = sum(1 for y, p in pairs if y == 1 and p < threshold)
    fp = sum(1 for y, p in pairs if y == 0 and p >= threshold)
    tn = sum(1 for y, p in pairs if y == 0 and p < threshold)
    return {"n": len(pairs), "accuracy": round((tp + tn) / len(pairs), 4), "auc": auc(pairs),
            "metrowerks_precision": round(tp / max(tp + fp, 1), 4), "metrowerks_recall": round(tp / max(tp + fn, 1), 4),
            "psp_gcc_recall": round(tn / max(tn + fp, 1), 4), "confusion": {"tp": tp, "fn": fn, "fp": fp, "tn": tn}}


def evaluate(folds: int = 5) -> dict:
    mods = load_functions()
    all_fns = [fn for fns in mods.values() for fn in fns]
    for fns in mods.values():
        add_neighbours(fns)
    known = [fn for fn in all_fns if fn.label is not None]
    groups = sorted({fn.group for fn in known})
    fold_of = {g: int(hashlib.md5(g.encode()).hexdigest(), 16) % folds for g in groups}
    result = {"known_functions": len(known), "metrowerks": sum(fn.label for fn in known),
              "psp_gcc": sum(1 - fn.label for fn in known), "by_module": {m: len([f for f in fns if f.label is not None]) for m, fns in mods.items()},
              "unresolved": {m: len([f for f in fns if f.label is None]) for m, fns in mods.items()},
              "feature_sets": {}}
    for name, names in (("code_only", CODE_ONLY), ("code_and_address", WITH_ADDRESS), ("code_address_neighbours", FEATURES)):
        scored: list[tuple[Fn, float]] = []
        for k in range(folds):
            train = [fn for fn in known if fold_of[fn.group] != k]
            test = [fn for fn in known if fold_of[fn.group] == k]
            model = Logistic(names)
            model.fit(train)
            scored += [(fn, model.prob(fn.feat)) for fn in test]
        res = metrics([(fn.label, p) for fn, p in scored])
        # the queue's default floor is 0x88000: report both sides (there are only a handful of psp-gcc functions above it)
        res["at_or_above_0x88000"] = metrics([(fn.label, p) for fn, p in scored if fn.start >= 0x88000])
        res["below_0x88000"] = metrics([(fn.label, p) for fn, p in scored if fn.start < 0x88000])
        result["feature_sets"][name] = res
    return result


def predict(out: Path, feature_set: str = "code_address_neighbours") -> dict:
    mods = load_functions()
    names = {"code_only": CODE_ONLY, "code_and_address": WITH_ADDRESS, "code_address_neighbours": FEATURES}[feature_set]
    rows = {}
    for mod, fns in mods.items():
        add_neighbours(fns)
        known = [fn for fn in fns if fn.label is not None]
        model = Logistic(names)
        model.fit([fn for fns2 in mods.values() for fn in fns2 if fn.label is not None])
        for fn in fns:
            if fn.label is None:
                rows[f"{mod}:0x{fn.start:08x}"] = round(model.prob(fn.feat), 4)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps({"schema": "hst-decomp.family-predictions.v1", "feature_set": feature_set,
                               "meaning": "probability that the function is Metrowerks mwccpsp code (the rest is psp-gcc SDK code)",
                               "predictions": rows}, indent=0) + "\n", encoding="utf-8")
    return {"predicted": len(rows), "likely_metrowerks": sum(1 for p in rows.values() if p >= 0.5)}


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", choices=("evaluate", "predict"))
    ap.add_argument("--folds", type=int, default=5)
    ap.add_argument("--out", type=Path, default=ROOT / "try" / "family-predictions.json")
    ap.add_argument("--feature-set", default="code_address_neighbours",
                    choices=("code_only", "code_and_address", "code_address_neighbours"))
    args = ap.parse_args()
    if args.command == "evaluate":
        res = evaluate(args.folds)
        print(json.dumps(res, indent=1))
    else:
        print(json.dumps(predict(args.out, args.feature_set)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
