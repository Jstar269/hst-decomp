#!/usr/bin/env python3
"""Side-by-side disassembly of a source's linked bytes against the retail bytes (after hstmatch.py)."""
from __future__ import annotations

import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstmatch as M


def disasm(path: Path, vma: int) -> list[str]:
    out = subprocess.run(["wsl.exe", "-e", f"{M.PSPDEV_BIN}/psp-objdump", "-D", "-z", "-b", "binary", "-m", "mips:allegrex",
                          "-EL", f"--adjust-vma=0x{vma:x}", M.to_wsl(path)], capture_output=True, text=True).stdout
    rows = []
    for line in out.splitlines():
        parts = line.split("\t")
        if len(parts) >= 3 and parts[0].strip().endswith(":"):
            rows.append(f"{parts[1].strip()} {' '.join(p.strip() for p in parts[2:])}")
    return rows


def main() -> int:
    for arg in sys.argv[1:]:
        src = Path(arg).resolve()
        h = M.parse_header(src)
        out = M.ROOT / "build" / h["module"] / f"{src.parent.name}__{src.stem}"
        cache: dict = {}
        data, seg = M.module_bytes(cache, h["module"])
        off = seg["file_offset"] + h["start"] - seg["start"]
        target = out / "target.bin"
        target.write_bytes(data[off:off + h["end"] - h["start"]])
        ours = disasm(out / "text.bin", h["start"]) if (out / "text.bin").exists() else []
        theirs = disasm(target, h["start"])
        print(f"== {src.name}  (ours | retail)")
        for i in range(max(len(ours), len(theirs))):
            a = ours[i] if i < len(ours) else ""
            b = theirs[i] if i < len(theirs) else ""
            mark = "  " if a.split(" ")[0:1] == b.split(" ")[0:1] else "**"
            print(f"{mark} {h['start'] + 4 * i:08x}  {a:<44.44} | {b}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
