#!/usr/bin/env python3
"""PSP relocation tables, the container of a PSP module, and the shifted-build expectation (docs/RELOCATION.md).

    python tools/hstreloc.py <module> [--shift N]     decode the retail tables of one module and print what they hold

The pure parts of the whole-module build (tools/hstbuild.py) that deal with relocation records live here, so they
can be tested on synthetic data (tools/test_hstbuild.py):

  * format A (section or program header type 0x700000A0): 8-byte entries (r_offset, r_info), little-endian.
      r_offset   the site (the relocated word), relative to the base of the offset segment
      r_info     bits 0-7 the type (R_MIPS_32 = 2, R_MIPS_26 = 4, R_MIPS_HI16 = 5, R_MIPS_LO16 = 6),
                 bits 8-15 the offset segment (index of the PT_LOAD the site lies in),
                 bits 16-23 the address segment (the PT_LOAD whose load base is added to the target),
                 bits 24-31 zero.
    A HI16 entry carries no addend of its own: the loader adds the sign-extended low half of the word of the next
    entry that is not HI16 (its partner, always a LO16) to the HI16's immediate shifted by 16. A table therefore
    keeps every run of HI16 entries immediately before the LO16 it belongs to.
  * format B (program header type 0x700000A1, the Sony library modules): a compressed command stream, decoded here
    (`decode_b`) into the same records; it is not regenerated yet.
  * target recovery: the address each relocated word refers to (`recover_targets`), from the table and the words.
  * the order of a table: blocks of entries per tile (`blocks_of`, `runs_of`): .rel.text is one block per function in
    address order; inside a block the entries are in the compiler's emission order; a HI16 belongs to the block of
    its partner.
  * the shifted-build expectation (`expected_shift`): the retail image with every section moved, every relocated
    word moved with its target. It does not use the build's symbols; it is the independent half of gate 5's static
    check.
  * the container (`write_module`): ELF header, program header, section header table, .shstrtab, .comment and the
    relocation sections laid out from the build's own sections by one of the two observed container profiles.
"""
from __future__ import annotations

import argparse
import struct
from dataclasses import dataclass, field
from typing import Callable, Iterable, Sequence

SHT_PSP_REL = 0x700000A0          # format A: as a section type (EBOOT, Sharing) and as a program header type
PT_PSP_REL_B = 0x700000A1         # format B: program header type only
R_MIPS_32, R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 2, 4, 5, 6
TYPE_NAMES = {0: "R_MIPS_NONE", 2: "R_MIPS_32", 4: "R_MIPS_26", 5: "R_MIPS_HI16", 6: "R_MIPS_LO16", 7: "R_MIPS_GPREL16"}
KNOWN_TYPES = frozenset((R_MIPS_32, R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16))


def sext16(v: int) -> int:
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def rs_of(w: int) -> int:
    return (w >> 21) & 31


def rt_of(w: int) -> int:
    return (w >> 16) & 31


# --------------------------------------------------------------------------------------------------------------
# format A

@dataclass(frozen=True)
class Entry:
    offset: int
    type: int
    oseg: int = 0
    aseg: int = 0

    @property
    def info(self) -> int:
        return self.type | (self.oseg << 8) | (self.aseg << 16)


def decode_a(data: bytes, nseg: int | None = None) -> list[Entry]:
    """The entries of one format-A table. Refuses a table whose layout differs from the one documented above: a size
    that is not a multiple of 8, non-zero bits 24-31, a segment index beyond `nseg`, or an unknown type."""
    if len(data) % 8:
        raise ValueError(f"format A table of {len(data)} bytes is not a multiple of 8")
    out = []
    for k in range(0, len(data), 8):
        off, info = struct.unpack_from("<II", data, k)
        if info >> 24:
            raise ValueError(f"entry {k // 8}: bits 24-31 of r_info are {info >> 24:#x}, not zero")
        e = Entry(off, info & 0xFF, (info >> 8) & 0xFF, (info >> 16) & 0xFF)
        if nseg is not None and (e.oseg >= nseg or e.aseg >= nseg):
            raise ValueError(f"entry {k // 8}: segment index {e.oseg}/{e.aseg} beyond the {nseg} segments")
        if e.type not in KNOWN_TYPES:
            raise ValueError(f"entry {k // 8}: relocation type {e.type} is not one this tool knows")
        out.append(e)
    return out


def encode_a(entries: Iterable[Entry]) -> bytes:
    return b"".join(struct.pack("<II", e.offset, e.info) for e in entries)


def partner_index(entries: Sequence[Entry]) -> list[int | None]:
    """For every HI16 entry the index of its partner (the first entry after its HI16 run); None for the others.
    A HI16 run at the end of a table has no partner, which the PSP loader refuses: ValueError."""
    out: list[int | None] = [None] * len(entries)
    k = 0
    while k < len(entries):
        if entries[k].type != R_MIPS_HI16:
            k += 1
            continue
        j = k
        while j < len(entries) and entries[j].type == R_MIPS_HI16:
            j += 1
        if j == len(entries):
            raise ValueError(f"HI16 run at entry {k} has no partner")
        for h in range(k, j):
            out[h] = j
        k = j + 1
    return out


# --------------------------------------------------------------------------------------------------------------
# format B (decode only)

FORMAT_B_KIND = {1: R_MIPS_LO16, 2: R_MIPS_32, 3: R_MIPS_26, 4: R_MIPS_HI16, 5: R_MIPS_LO16, 6: R_MIPS_26, 7: R_MIPS_26}


@dataclass(frozen=True)
class EntryB:
    oseg: int
    offset: int
    kind: int        # the format-B kind number (FORMAT_B_KIND maps it to the MIPS type)
    aseg: int
    addend: int      # HI16 (kind 4) only: the low half the loader adds; 0 otherwise

    @property
    def type(self) -> int:
        return FORMAT_B_KIND[self.kind]


def _sext(v: int, bits: int) -> int:
    if bits <= 0:
        return 0
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def decode_b(data: bytes, nseg: int) -> list[EntryB]:
    """The command stream of a format-B table as records. Header: two zero bytes, the flag-field width f, the
    kind-field width t; a flag table (count byte, then flags) and a kind table (count byte, then kinds). Each command
    is a 16-bit word: flag index (f bits), address segment (1 bit, 2 when there are 3 or more segments), kind index
    (t bits), and a signed displacement in the rest. A flag with bit 0 clear sets the current offset segment and
    offset; with bit 0 set it relocates one word: bits 1-2 choose the offset form (displacement, displacement with a
    16-bit extension, absolute 32-bit), bits 3-5 the addend form of a HI16 (none, the previous HI16's, 16-bit)."""
    if len(data) < 5 or data[0] or data[1]:
        raise ValueError("format B header")
    f, t = data[2], data[3]
    segw = 2 if nseg >= 3 else 1
    nf = data[4]
    nk_off = 4 + nf
    nk = data[nk_off]
    flags = data[4:4 + nf]
    kinds = data[nk_off:nk_off + nk]
    pos = nk_off + nk
    dw = 16 - f - segw - t
    cur_seg = cur_off = 0
    prev_kind, prev_add = -1, 0
    out: list[EntryB] = []
    while pos < len(data):
        cc, = struct.unpack_from("<H", data, pos)
        pos += 2
        fi = cc & ((1 << f) - 1)
        seg = (cc >> f) & ((1 << segw) - 1)
        ki = (cc >> (f + segw)) & ((1 << t) - 1)
        draw = cc >> (f + segw + t)
        if not 0 < fi < nf:
            raise ValueError(f"format B flag index {fi} at byte {pos - 2}")
        g = flags[fi]
        if not g & 1:
            cur_seg = seg
            if g & 6 == 0:
                cur_off = cc >> (f + segw)
            elif g & 6 == 4:
                cur_off, = struct.unpack_from("<I", data, pos)
                pos += 4
            else:
                raise ValueError(f"format B set-offset form {g:#x}")
            continue
        if not 0 < ki < nk:
            raise ValueError(f"format B kind index {ki} at byte {pos - 2}")
        kind = kinds[ki]
        if g & 6 == 0:
            cur_off += _sext(draw, dw)
        elif g & 6 == 2:
            ext, = struct.unpack_from("<H", data, pos)
            pos += 2
            cur_off += ((_sext(draw, dw) << 16) | ext)
        elif g & 6 == 4:
            cur_off, = struct.unpack_from("<I", data, pos)
            pos += 4
        else:
            raise ValueError(f"format B offset form {g:#x}")
        cur_off &= 0xFFFFFFFF
        b345 = (g >> 3) & 7
        if b345 == 0:
            add = 0
        elif b345 == 1:
            add = prev_add if prev_kind == 4 else 0
        elif b345 == 2:
            ext, = struct.unpack_from("<H", data, pos)
            pos += 2
            add = sext16(ext)
        else:
            raise ValueError(f"format B addend form {g:#x}")
        if kind not in FORMAT_B_KIND:
            raise ValueError(f"format B kind {kind}")
        out.append(EntryB(cur_seg, cur_off, kind, seg, add))
        prev_kind, prev_add = kind, add
    return out


# --------------------------------------------------------------------------------------------------------------
# targets: what each relocated word refers to

def recover_targets(entries: Sequence[Entry], word_at: Callable[[int], int],
                    function_of: Callable[[int], tuple[int, int]] | None = None,
                    inside: Callable[[int], bool] | None = None) -> list[int | None]:
    """The address each entry's word refers to, in a single-segment module (offsets are addresses):
      R_MIPS_32   the word;
      R_MIPS_26   the jump target, (site & 0xf0000000) | (field << 2);
      R_MIPS_HI16 (immediate << 16) + sext16(the partner's immediate), the PSP loader's own rule;
      R_MIPS_LO16 after a HI16 run: that run's target; alone (it reuses a register an earlier lui loaded): the high half
                  comes from the nearest HI16 of the same function whose lui writes the register the LO16 reads
                  (preceding, else following), else from the nearest HI16 of the function; candidates whose
                  target falls outside the module (`inside`) are passed over. None when nothing fits.
    Only the low 16 bits of a standalone LO16 are fixed by its word; the recovered high half only decides which
    section (and so which move under a shifted build) the target belongs to."""
    partner = partner_index(entries)
    out: list[int | None] = [None] * len(entries)
    hi_by_func: dict[tuple[int, int], list[tuple[int, int, int]]] = {}
    for k, e in enumerate(entries):
        w = word_at(e.offset)
        if e.type == R_MIPS_32:
            out[k] = w
        elif e.type == R_MIPS_26:
            out[k] = (e.offset & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
        elif e.type == R_MIPS_HI16:
            out[k] = (((w & 0xFFFF) << 16) + sext16(word_at(entries[partner[k]].offset))) & 0xFFFFFFFF
            if function_of is not None:
                hi_by_func.setdefault(function_of(e.offset), []).append((e.offset, rt_of(w), w & 0xFFFF))
    for k, e in enumerate(entries):
        if e.type != R_MIPS_LO16:
            continue
        if k > 0 and entries[k - 1].type == R_MIPS_HI16:
            out[k] = out[k - 1]
            continue
        w = word_at(e.offset)
        cands = hi_by_func.get(function_of(e.offset), []) if function_of is not None else []
        lo = sext16(w)
        if inside is not None:
            cands = [c for c in cands if inside(((c[2] << 16) + lo) & 0xFFFFFFFF)]
        reg = [c for c in cands if c[1] == rs_of(w)] or cands
        if not reg:
            continue
        before = [c for c in reg if c[0] < e.offset]
        pick = max(before) if before else min(reg)
        out[k] = ((pick[2] << 16) + sext16(w)) & 0xFFFFFFFF
    return out


# --------------------------------------------------------------------------------------------------------------
# order: blocks and runs

def block_owner(entries: Sequence[Entry], owner_of: Callable[[int], int]) -> list[int]:
    """The tile (owner_of(address) -> tile key) each entry belongs to: its own site's tile, or for a HI16 the tile of
    its partner's site (the HI16 sits in front of its partner, wherever that is)."""
    partner = partner_index(entries)
    return [owner_of(entries[partner[k]].offset if e.type == R_MIPS_HI16 else e.offset) for k, e in enumerate(entries)]


def runs_of(owners: Sequence[int]) -> list[tuple[int, int, int]]:
    """Maximal runs of equal owners: [(owner, first index, count)]."""
    out: list[tuple[int, int, int]] = []
    for k, o in enumerate(owners):
        if out and out[-1][0] == o:
            out[-1] = (o, out[-1][1], out[-1][2] + 1)
        else:
            out.append((o, k, 1))
    return out


def is_address_ordered(runs: Sequence[tuple[int, int, int]]) -> bool:
    """True when the table is one block per owner, the owners in ascending order (the .rel.text rule)."""
    keys = [r[0] for r in runs]
    return len(set(keys)) == len(keys) and keys == sorted(keys)


# --------------------------------------------------------------------------------------------------------------
# the shifted build

@dataclass(frozen=True)
class Shift:
    """Padding of `n` bytes ahead of the code and `n` more ahead of the data: an address below `data_start` moves by n,
    one at or above it by 2n."""
    n: int
    data_start: int

    def delta(self, addr: int) -> int:
        return self.n if addr < self.data_start else 2 * self.n


@dataclass
class ShiftFailure(Exception):
    where: int
    why: str

    def __str__(self) -> str:
        return f"0x{self.where:08x}: {self.why}"


def lo16_class_targets(entries: Sequence[Entry], word_at: Callable[[int], int],
                       function_of: Callable[[int], tuple[int, int]], data_start: int) -> dict[int, bool]:
    """{index of a standalone LO16: True when its target is data (at or above data_start)}, decided by the set of all
    HI16 of the function whose lui writes the register the LO16 reads (else all HI16 of the function): every candidate
    must agree, otherwise ShiftFailure. Written apart from recover_targets on purpose (see expected_shift)."""
    partner = partner_index(entries)
    his: dict[tuple[int, int], list[tuple[int, int]]] = {}
    for k, e in enumerate(entries):
        if e.type == R_MIPS_HI16:
            w = word_at(e.offset)
            his.setdefault(function_of(e.offset), []).append((rt_of(w), (w & 0xFFFF) << 16))
    out = {}
    for k, e in enumerate(entries):
        if e.type != R_MIPS_LO16 or (k and entries[k - 1].type == R_MIPS_HI16):
            continue
        w = word_at(e.offset)
        cands = his.get(function_of(e.offset), [])
        regs = [h for r, h in cands if r == rs_of(w)] or [h for _r, h in cands]
        classes = {((h + sext16(w)) & 0xFFFFFFFF) >= data_start for h in regs}
        if len(classes) != 1:
            raise ShiftFailure(e.offset, f"standalone LO16: cannot tell code from data ({len(regs)} candidate HI16)")
        out[k] = classes.pop()
    del partner
    return out


def expected_shift(sections: Sequence[tuple[str, int, bytes]], tables: Sequence[Sequence[Entry]],
                   function_of: Callable[[int], tuple[int, int]], shift: Shift) -> dict[str, tuple[int, bytes]]:
    """The image a correct shifted build must produce, from the RETAIL sections [(name, address, bytes)] and the
    RETAIL relocation tables only: every section at address + shift.delta(address); every relocated word moved by the
    delta of its target, following the PSP loader's arithmetic (R_MIPS_32 word + d; R_MIPS_26 field of (target + d);
    HI16 the carry-adjusted high half of target + d, with target = imm << 16 + sext16(partner); LO16 imm + d).
    Raises ShiftFailure naming the site when a word cannot be moved (a jump that would leave its 256 MB region)."""
    by_addr = sorted(sections, key=lambda s: s[1])
    new = {name: bytearray(data) for name, _a, data in by_addr}

    def locate(addr: int) -> tuple[str, int]:
        for name, a, data in by_addr:
            if a <= addr < a + len(data):
                return name, addr - a
        raise ShiftFailure(addr, "relocated word outside every section")

    def read(addr: int) -> int:
        name, off = locate(addr)
        return struct.unpack_from("<I", new[name], off)[0]

    for table in tables:
        if not table:
            continue
        partner = partner_index(table)
        lo_data = lo16_class_targets(table, lambda a: read(a), function_of, shift.data_start)
        # first every target from the unmodified words (a HI16 reads its partner before the partner moves)
        moves = []
        for k, e in enumerate(table):
            w = read(e.offset)
            if e.type == R_MIPS_32:
                nw = (w + shift.delta(w)) & 0xFFFFFFFF
            elif e.type == R_MIPS_26:
                t = (e.offset & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
                nt = t + shift.delta(t)
                if (nt & 0xF0000000) != ((e.offset + shift.delta(e.offset)) & 0xF0000000):
                    raise ShiftFailure(e.offset, "jump target leaves the 256 MB region")
                nw = (w & 0xFC000000) | ((nt >> 2) & 0x03FFFFFF)
            elif e.type == R_MIPS_HI16:
                t = (((w & 0xFFFF) << 16) + sext16(read(table[partner[k]].offset))) & 0xFFFFFFFF
                nt = t + shift.delta(t)
                nw = (w & 0xFFFF0000) | (((nt + 0x8000) >> 16) & 0xFFFF)
            elif e.type == R_MIPS_LO16:
                if k and table[k - 1].type == R_MIPS_HI16:
                    hw = read(table[k - 1].offset)
                    t = (((hw & 0xFFFF) << 16) + sext16(w)) & 0xFFFFFFFF
                    d = shift.delta(t)
                else:
                    d = 2 * shift.n if lo_data[k] else shift.n
                nw = (w & 0xFFFF0000) | ((w + d) & 0xFFFF)
            else:
                raise ShiftFailure(e.offset, f"relocation type {e.type}")
            moves.append((e.offset, nw))
        for addr, nw in moves:
            name, off = locate(addr)
            struct.pack_into("<I", new[name], off, nw)
    return {name: (a + shift.delta(a), bytes(new[name])) for name, a, _d in by_addr}


def shifted_table(entries: Sequence[Entry], shift: Shift) -> list[Entry]:
    """The relocation table of the shifted image: the same entries in the same order, every site moved."""
    return [Entry(e.offset + shift.delta(e.offset), e.type, e.oseg, e.aseg) for e in entries]


def first_difference(a: bytes, b: bytes) -> int | None:
    if a == b:
        return None
    n = min(len(a), len(b))
    return next((i for i in range(n) if a[i] != b[i]), n)


# --------------------------------------------------------------------------------------------------------------
# the container

@dataclass(frozen=True)
class ContainerProfile:
    """How a PSP post-link tool lays the parts of the file out. Two tools are observed: the EBOOT's (load content right
    after the program header, then the section header table, the relocation tables, .shstrtab and .comment, the file
    padded to 4; relocation sections with sh_link 3 and sh_info = target index + 2) and the Sharing Version's (load
    content at 16, then .comment, .shstrtab, the section header table, the relocation tables; sh_link 0, sh_info =
    target index)."""
    name: str
    content_align: int
    trailer: tuple[str, ...]          # order of "comment", "shstrtab", "shdrs", "rels"
    comment_align: int
    end_align: int
    rel_link: int | None              # None: 0
    rel_info_bias: int


PROFILES = {
    "eboot": ContainerProfile("eboot", 1, ("shdrs", "rels", "shstrtab", "comment"), 4, 4, 3, 2),
    "sharing": ContainerProfile("sharing", 16, ("comment", "shstrtab", "shdrs", "rels"), 1, 1, None, 0),
}


@dataclass
class OutSection:
    name: str
    addr: int
    data: bytes | None               # None: NOBITS (no file content)
    flags: int
    align: int = 16
    rel: bytes | None = None         # the format-A table of this section, or None for no relocation section
    size: int | None = None          # NOBITS size in the header (0 for the PSP .bss)

    @property
    def hdr_size(self) -> int:
        return len(self.data) if self.data is not None else (self.size or 0)


SH = struct.Struct("<IIIIIIIIII")
EH = struct.Struct("<16sHHIIIIIHHHHHH")


@dataclass(frozen=True)
class ModuleOptions:
    """Options for writing a target PRX image containing module headers, comment, entry point, and memory size."""
    entry: int
    comment: bytes
    memsz_end: int
    modinfo_name: str = ".rodata.sceModuleInfo"
    ident: bytes | None = None
    e_flags: int = 0x10A23001


def write_module(profile: ContainerProfile, sections: Sequence[OutSection],
                 options: ModuleOptions) -> tuple[bytes, dict[str, tuple[int, int]]]:
    """The whole module file from its sections (address order; their file offsets follow from the addresses, as in a
    PSP executable with one PT_LOAD at 0). Returns the file and {part: (offset, size)} of every part, for reporting."""
    ident = options.ident or (b"\x7fELF\x01\x01\x01" + bytes(9))
    order: list[tuple[str, int]] = [("", 0), (".shstrtab", 0)]       # (name, kind): 0 = special, 1 = loaded, 2 = rel
    for s in sections:
        order.append((s.name, 1))
        if s.rel is not None:
            order.append((".rel" + s.name, 2))
    order.append((".comment", 0))
    names = bytearray(b"\0")
    name_off = {}
    for n, _k in order[1:]:
        name_off[n] = len(names)
        names += n.encode() + b"\0"
    content_off = EH.size + 32
    content_off += -content_off % profile.content_align
    by_name = {s.name: s for s in sections}
    content_end = max(s.addr + len(s.data) for s in sections if s.data is not None)
    parts: dict[str, tuple[int, int]] = {"content": (content_off, content_end)}
    pos = content_off + content_end
    shnum = len(order)
    rel_blobs = [(".rel" + s.name, s.rel) for s in sections if s.rel is not None]
    offsets: dict[str, int] = {}
    for part in profile.trailer:
        if part == "comment":
            pos += -pos % profile.comment_align
            offsets[".comment"] = pos
            pos += len(options.comment)
        elif part == "shstrtab":
            offsets[".shstrtab"] = pos
            pos += len(names)
        elif part == "shdrs":
            pos += -pos % 4
            offsets["shdrs"] = pos
            pos += shnum * SH.size
        elif part == "rels":
            for n, blob in rel_blobs:
                offsets[n] = pos
                pos += len(blob)
    total = pos + (-pos % profile.end_align)
    out = bytearray(total)
    index = {n: i for i, (n, _k) in enumerate(order)}
    shdrs = bytearray()
    for i, (n, kind) in enumerate(order):
        if i == 0:
            shdrs += SH.pack(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        elif n == ".shstrtab":
            shdrs += SH.pack(name_off[n], 3, 0, 0, offsets[n], len(names), 0, 0, 1, 1)
        elif n == ".comment":
            shdrs += SH.pack(name_off[n], 1, 0, 0, offsets[n], len(options.comment), 0, 0, 1, 1)
        elif kind == 1:
            s = by_name[n]
            shdrs += SH.pack(name_off[n], 8 if s.data is None else 1, s.flags, s.addr, content_off + s.addr, s.hdr_size,
                             0, 0, s.align, 1)
        else:
            target = index[n[4:]]
            link = profile.rel_link if profile.rel_link is not None else 0
            blob = by_name[n[4:]].rel
            shdrs += SH.pack(name_off[n], SHT_PSP_REL, 0, 0, offsets[n], len(blob), link, target + profile.rel_info_bias,
                             0, 8)
    for s in sections:
        if s.data is not None:
            out[content_off + s.addr:content_off + s.addr + len(s.data)] = s.data
    out[offsets["shdrs"]:offsets["shdrs"] + len(shdrs)] = shdrs
    out[offsets[".shstrtab"]:offsets[".shstrtab"] + len(names)] = names
    out[offsets[".comment"]:offsets[".comment"] + len(options.comment)] = options.comment
    for n, blob in rel_blobs:
        out[offsets[n]:offsets[n] + len(blob)] = blob
    modinfo = by_name[options.modinfo_name]
    ph = struct.pack("<IIIIIIII", 1, content_off, 0, content_off + modinfo.addr, content_end, options.memsz_end, 7, 16)
    out[:EH.size] = EH.pack(ident, 0xFFA0, 8, 1, options.entry, EH.size, offsets["shdrs"], options.e_flags, EH.size, 32, 1, SH.size,
                            shnum, 1)
    out[EH.size:EH.size + 32] = ph
    parts.update({"elf_header": (0, EH.size), "program_header": (EH.size, 32), "section_headers": (offsets["shdrs"], len(shdrs)),
                  ".shstrtab": (offsets[".shstrtab"], len(names)), ".comment": (offsets[".comment"], len(options.comment))})
    for n, blob in rel_blobs:
        parts[n] = (offsets[n], len(blob))
    return bytes(out), parts


MODULE_START_NID = 0xD632ACDB


def module_start(lib_ent: bytes, word_at: Callable[[int], int]) -> int | None:
    """The address of module_start, the ELF entry point: the export entries of .lib.ent are 16-byte records (libname,
    version, attributes, length in words, variable count, function count, entry table); the system export (libname
    0) has a table of nfunc + nvar NIDs followed by as many values, and module_start is the function NID 0xD632ACDB."""
    off = 0
    while off + 16 <= len(lib_ent):
        libname, _ver, _attr, words, nvar, nfunc, table = struct.unpack_from("<IHHBBHI", lib_ent, off)
        if libname == 0:
            for i in range(nfunc):
                if word_at(table + 4 * i) == MODULE_START_NID:
                    return word_at(table + 4 * (nfunc + nvar + i))
        off += max(words, 4) * 4
    return None


# --------------------------------------------------------------------------------------------------------------

def main() -> int:
    import sys
    from pathlib import Path
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    import hstbuild as B
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("module")
    args = ap.parse_args()
    retail, _cache = B.load_retail(args.module)
    nseg = len(retail.segments)
    for sec in retail.elf.secs:
        if sec.type == SHT_PSP_REL:
            ents = decode_a(sec.data or b"", nseg)
            kinds: dict[str, int] = {}
            for e in ents:
                kinds[TYPE_NAMES[e.type]] = kinds.get(TYPE_NAMES[e.type], 0) + 1
            print(f"{sec.name:28} {len(ents):7} entries  {kinds}")
    data = retail.data
    phoff, phnum = retail.elf.ehdr[5], retail.elf.ehdr[10]
    for i in range(phnum):
        p_type, p_off, _va, _pa, p_filesz = struct.unpack_from("<IIIII", data, phoff + 32 * i)
        if p_type == PT_PSP_REL_B:
            ents_b = decode_b(data[p_off:p_off + p_filesz], nseg)
            kinds = {}
            for e in ents_b:
                kinds[TYPE_NAMES[e.type]] = kinds.get(TYPE_NAMES[e.type], 0) + 1
            print(f"program header {i} (format B)   {len(ents_b):7} entries  {kinds}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
