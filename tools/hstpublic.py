#!/usr/bin/env python3
"""Maintainer tool: keep the public branch in step with the full working branch.

    python tools/hstpublic.py sync --worktree <public worktree> -m <commit message>
    python tools/hstpublic.py check <commit>          # used by the pre-push hook

The maintainer's own repository has two branches. The local-only `full` branch tracks everything, including the
Sony SDK reconstructions that tools/hstpublish.py leaves out (EXCLUDED_CLASSES). The `public` branch, checked out
in a separate git worktree and pushed as the remote's `main`, only ever receives what hstpublish.py copies, so
neither its tree nor its history contains an excluded source.

`sync` runs hstpublish.py into a temporary directory, mirrors that tree into the public worktree (adding,
replacing and deleting files; `.git` is left alone) and commits it there when anything changed. It never pushes.

`check` refuses a commit whose tree contains a source (src/, wip/) that the commit's own ORIGINS.json does not
list, or lists with an excluded class. The pre-push hook runs it on every pushed commit and refuses any ref other
than `public`.
"""
from __future__ import annotations

import argparse
import json
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstpublish

ROOT = hstpublish.ROOT


def git(cwd: Path, *args: str, text: bool = True) -> str:
    return subprocess.run(["git", *args], cwd=cwd, check=True, capture_output=True, text=text).stdout


def mirror(src: Path, dst: Path) -> None:
    """Make dst's tracked files equal to src's files; untracked and ignored files in dst (build/, try/,
    hst-config.json) are left alone."""
    want = {p.relative_to(src).as_posix() for p in src.rglob("*") if p.is_file()}
    for rel in git(dst, "ls-files").splitlines():
        if rel not in want and (dst / rel).is_file():
            (dst / rel).unlink()
            parent = (dst / rel).parent
            while parent != dst and parent.is_dir() and not any(parent.iterdir()):
                parent.rmdir()
                parent = parent.parent
    for rel in want:
        (dst / rel).parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(src / rel, dst / rel)


def sync(worktree: Path, message: str) -> int:
    if not (worktree / ".git").exists():
        raise SystemExit(f"{worktree} is not a git worktree")
    if git(worktree, "symbolic-ref", "--short", "HEAD").strip() != "public":
        raise SystemExit(f"{worktree} does not have the public branch checked out")
    with tempfile.TemporaryDirectory() as tmp:
        out = Path(tmp) / "tree"
        subprocess.run([sys.executable, str(ROOT / "tools" / "hstpublish.py"), "--out", str(out)], check=True)
        mirror(out, worktree)
    git(worktree, "add", "-A")
    if not git(worktree, "status", "--porcelain").strip():
        print("public branch already up to date")
        return 0
    rc = check_tree(worktree, None)
    if rc:
        return rc
    subprocess.run(["git", "commit", "-q", "-F", "-"], cwd=worktree, input=message, text=True, check=True)
    print(git(worktree, "log", "-1", "--oneline").strip())
    return 0


def check_tree(worktree: Path | None, commit: str | None) -> int:
    """0 when every source in the tree is listed in its ORIGINS.json with a publishable class."""
    if commit is None:
        files = git(worktree, "ls-files").splitlines()
        origins = json.loads((worktree / "ORIGINS.json").read_text(encoding="utf-8"))
    else:
        files = git(ROOT, "ls-tree", "-r", "--name-only", commit).splitlines()
        origins = json.loads(git(ROOT, "show", f"{commit}:ORIGINS.json"))
    bad = []
    for f in files:
        if f.split("/")[0] in ("src", "wip") and f.endswith((".c", ".cpp")):
            cls = origins.get(f)
            if cls is None or cls in hstpublish.EXCLUDED_CLASSES:
                bad.append(f"{f}: {cls or 'not in ORIGINS.json'}")
    bad += [f"ORIGINS.json lists {p} as {c}" for p, c in origins.items() if c in hstpublish.EXCLUDED_CLASSES]
    for b in bad[:20]:
        print(f"REFUSED {b}", file=sys.stderr)
    if bad:
        print(f"REFUSED: {len(bad)} non-publishable entr(y/ies)", file=sys.stderr)
        return 1
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("sync")
    s.add_argument("--worktree", type=Path, required=True)
    s.add_argument("-m", "--message", required=True)
    c = sub.add_parser("check")
    c.add_argument("commit")
    args = ap.parse_args()
    if args.cmd == "sync":
        return sync(args.worktree.resolve(), args.message)
    return check_tree(None, args.commit)


if __name__ == "__main__":
    raise SystemExit(main())
