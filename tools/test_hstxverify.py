"""Synthetic ELF and fail-closed regression tests for hstxverify."""

from __future__ import annotations

import os
import struct
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstxverify as verifier  # noqa: E402


def synthetic_elf(
    text: bytes = b"\x11\x22\x33\x44",
    rodata: bytes = b"",
    rodata_addr: int = 0x1004,
    symbol: str = "FUN_00001000",
) -> bytes:
    """Build a small linked ELF32 with one PT_LOAD and optional placed .rodata."""
    base = 0x1000
    ro_addr = rodata_addr
    max_addr = max(
        base + len(text), ro_addr + len(rodata) if rodata else base + len(text)
    )
    load = bytearray(max_addr - base)
    load[: len(text)] = text
    if rodata:
        offset = ro_addr - base
        load[offset : offset + len(rodata)] = rodata

    payload_offset = 0x100
    string_data = b"\0" + symbol.encode("ascii") + b"\0"
    symbol_data = bytes(16) + struct.pack("<IIIBBH", 1, base, len(text), 0x12, 0, 1)
    section_names = ["", ".text"]
    section_rows = [
        None,
        {
            "name": ".text",
            "type": 1,
            "flags": 6,
            "addr": base,
            "offset": payload_offset,
            "size": len(text),
            "link": 0,
            "info": 0,
            "align": 4,
            "entsize": 0,
        },
    ]
    if rodata:
        section_names.append(".rodata")
        section_rows.append(
            {
                "name": ".rodata",
                "type": 1,
                "flags": 2,
                "addr": ro_addr,
                "offset": payload_offset + ro_addr - base,
                "size": len(rodata),
                "link": 0,
                "info": 0,
                "align": 4,
                "entsize": 0,
            }
        )
    strtab_index = len(section_rows)
    section_names.append(".strtab")
    section_rows.append(
        {
            "name": ".strtab",
            "type": 3,
            "flags": 0,
            "addr": 0,
            "offset": 0,
            "size": len(string_data),
            "link": 0,
            "info": 0,
            "align": 1,
            "entsize": 0,
        }
    )
    symtab_index = len(section_rows)
    section_names.append(".symtab")
    section_rows.append(
        {
            "name": ".symtab",
            "type": 2,
            "flags": 0,
            "addr": 0,
            "offset": 0,
            "size": len(symbol_data),
            "link": strtab_index,
            "info": 1,
            "align": 4,
            "entsize": 16,
        }
    )
    names = bytearray(b"\0")
    name_offsets = {"": 0}
    for name in section_names[1:]:
        name_offsets[name] = len(names)
        names.extend(name.encode("ascii") + b"\0")
    shstr_index = len(section_rows)
    section_names.append(".shstrtab")
    name_offsets[".shstrtab"] = len(names)
    names.extend(b".shstrtab\0")
    strtab_offset = payload_offset + len(load)
    symtab_offset = strtab_offset + len(string_data)
    shstr_offset = symtab_offset + len(symbol_data)
    section_rows[strtab_index]["offset"] = strtab_offset
    section_rows[symtab_index]["offset"] = symtab_offset
    section_rows.append(
        {
            "name": ".shstrtab",
            "type": 3,
            "flags": 0,
            "addr": 0,
            "offset": shstr_offset,
            "size": len(names),
            "link": 0,
            "info": 0,
            "align": 1,
            "entsize": 0,
        }
    )
    section_header_offset = shstr_offset + len(names)

    image = bytearray(section_header_offset + len(section_rows) * 40)
    image[:16] = b"\x7fELF" + bytes((1, 1, 1, 0, 0)) + bytes(7)
    struct.pack_into(
        "<HHIIIIIHHHHHH",
        image,
        16,
        2,
        8,
        1,
        base,
        52,
        section_header_offset,
        0,
        52,
        32,
        1,
        40,
        len(section_rows),
        shstr_index,
    )
    struct.pack_into(
        "<IIIIIIII",
        image,
        52,
        1,
        payload_offset,
        base,
        base,
        len(load),
        len(load),
        5,
        0x100,
    )
    image[payload_offset : payload_offset + len(load)] = load
    image[strtab_offset : strtab_offset + len(string_data)] = string_data
    image[symtab_offset : symtab_offset + len(symbol_data)] = symbol_data
    image[shstr_offset : shstr_offset + len(names)] = names
    for index, row in enumerate(section_rows):
        if row is None:
            continue
        nameoff = name_offsets[row["name"]]
        struct.pack_into(
            "<IIIIIIIIII",
            image,
            section_header_offset + index * 40,
            nameoff,
            row["type"],
            row["flags"],
            row["addr"],
            row["offset"],
            row["size"],
            row["link"],
            row["info"],
            row["align"],
            row["entsize"],
        )
    return bytes(image)


def synthetic_object_with_duplicate_text() -> bytes:
    """Build an ET_REL object whose target is in the second same-named .text section."""
    sections = [
        None,
        {
            "name": ".text",
            "type": 1,
            "flags": 6,
            "addr": 0,
            "offset": 0x80,
            "size": 4,
            "link": 0,
            "info": 0,
            "align": 4,
            "entsize": 0,
        },
        {
            "name": ".text",
            "type": 1,
            "flags": 6,
            "addr": 0,
            "offset": 0x84,
            "size": 4,
            "link": 0,
            "info": 0,
            "align": 4,
            "entsize": 0,
        },
    ]
    strings = b"\0FUN_00001000\0"
    symbols = bytes(16) + struct.pack("<IIIBBH", 1, 0, 4, 0x12, 0, 2)
    sections.append(
        {
            "name": ".strtab",
            "type": 3,
            "flags": 0,
            "addr": 0,
            "offset": 0,
            "size": len(strings),
            "link": 0,
            "info": 0,
            "align": 1,
            "entsize": 0,
        }
    )
    strtab_index = len(sections) - 1
    sections.append(
        {
            "name": ".symtab",
            "type": 2,
            "flags": 0,
            "addr": 0,
            "offset": 0,
            "size": len(symbols),
            "link": strtab_index,
            "info": 1,
            "align": 4,
            "entsize": 16,
        }
    )
    symtab_index = len(sections) - 1
    names = bytearray(b"\0")
    name_offsets = {"": 0}
    for name in (".text", ".strtab", ".symtab", ".shstrtab"):
        if name not in name_offsets:
            name_offsets[name] = len(names)
            names.extend(name.encode("ascii") + b"\0")
    strtab_offset = 0x88
    symtab_offset = strtab_offset + len(strings)
    shstr_offset = symtab_offset + len(symbols)
    sections[strtab_index]["offset"] = strtab_offset
    sections[symtab_index]["offset"] = symtab_offset
    sections.append(
        {
            "name": ".shstrtab",
            "type": 3,
            "flags": 0,
            "addr": 0,
            "offset": shstr_offset,
            "size": len(names),
            "link": 0,
            "info": 0,
            "align": 1,
            "entsize": 0,
        }
    )
    shstr_index = len(sections) - 1
    shoff = shstr_offset + len(names)
    image = bytearray(shoff + len(sections) * 40)
    image[:16] = b"\x7fELF" + bytes((1, 1, 1, 0, 0)) + bytes(7)
    struct.pack_into(
        "<HHIIIIIHHHHHH",
        image,
        16,
        1,
        8,
        1,
        0,
        0,
        shoff,
        0,
        52,
        32,
        0,
        40,
        len(sections),
        shstr_index,
    )
    image[0x80:0x88] = b"\x11\x22\x33\x44\xaa\xbb\xcc\xdd"
    image[strtab_offset : strtab_offset + len(strings)] = strings
    image[symtab_offset : symtab_offset + len(symbols)] = symbols
    image[shstr_offset : shstr_offset + len(names)] = names
    for index, row in enumerate(sections):
        if row is None:
            continue
        struct.pack_into(
            "<IIIIIIIIII",
            image,
            shoff + index * 40,
            name_offsets[row["name"]],
            row["type"],
            row["flags"],
            row["addr"],
            row["offset"],
            row["size"],
            row["link"],
            row["info"],
            row["align"],
            row["entsize"],
        )
    return bytes(image)


class ELFParserTests(unittest.TestCase):
    def test_parser_maps_virtual_addresses_through_load_segment(self):
        image = verifier.ELFImage(synthetic_elf(rodata=b"\xaa\xbb"), "synthetic")
        self.assertEqual(image.bytes_at(0x1000, 4), b"\x11\x22\x33\x44")
        self.assertEqual(image.bytes_at(0x1004, 2), b"\xaa\xbb")
        self.assertEqual(image.section(".text").addr, 0x1000)

    def test_parser_rejects_address_without_file_backing(self):
        image = verifier.ELFImage(synthetic_elf(), "synthetic")
        with self.assertRaises(verifier.ELFFormatError):
            image.bytes_at(0x2000, 1)

    def test_header_parser_reads_profile_and_data_placement(self):
        with tempfile.TemporaryDirectory() as temp:
            source = Path(temp) / "sample.c"
            source.write_text(
                "/* HSTMATCH module=EBOOT.BIN start=0x1000 end=0x1004 "
                "symbol=FUN_00001000 lang=c99 cc=gcc171-O2 data=0x2000 */\n",
                encoding="utf-8",
            )
            header = verifier.parse_header(source)
            self.assertEqual(header["profile"], "gcc171-O2")
            self.assertEqual(header["placements"], {"data": 0x2000})

    def test_compile_recipes_use_the_documented_profiles(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            source = root / "sample.cpp"
            obj, log, include = (
                root / "object.o",
                root / "compile.log",
                root / "include",
            )
            mwcc = verifier.compile_command(
                source,
                obj,
                log,
                {"profile": "mwcc219", "lang": "c++"},
                "$HOME/hst-mwcc",
                include,
                "$HOME/hst-gcc",
            )
            self.assertIn(
                "/builds/219/mwccpsp.exe -c -O4,p -sdatathreshold 0 -lang c++", mwcc
            )
            gcc = verifier.compile_command(
                source,
                obj,
                log,
                {"profile": "gcc171-O2", "lang": "c++"},
                "$HOME/hst-mwcc",
                include,
                "$HOME/hst-gcc",
            )
            self.assertIn("-B $HOME/hst-gcc/psp-gcc-1.7.1/lib/gcc-lib/psp/", gcc)
            self.assertIn("-c -O2 -G0 -fno-merge-constants -x c++", gcc)

    def test_target_symbol_selects_its_section_when_text_names_repeat(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            obj = root / "object.o"
            obj.write_bytes(synthetic_object_with_duplicate_text())
            output = root / "out"
            output.mkdir()
            command, _ = verifier.make_link_job(
                obj,
                output,
                {
                    "start": 0x1000,
                    "end": 0x1004,
                    "symbol": "FUN_00001000",
                    "placements": {},
                },
                {},
                "/opt/pspdev/bin",
            )
            self.assertIn("-Ttext=0x00001000", command)


class ComparisonTests(unittest.TestCase):
    def _header(self, **placements):
        return {
            "start": 0x1000,
            "end": 0x1004,
            "symbol": "FUN_00001000",
            "placements": placements,
        }

    def test_identical_code_matches_and_counts_bytes(self):
        retail = verifier.ELFImage(synthetic_elf(), "retail")
        linked = verifier.ELFImage(synthetic_elf(), "linked")
        report = verifier.image_comparison(retail, linked, self._header())
        self.assertEqual(report["status"], "MATCH")
        self.assertEqual(report["compared_bytes"], 4)
        self.assertIsNone(report["first_differing_offset"])

    def test_one_byte_change_reports_first_offset(self):
        retail = verifier.ELFImage(synthetic_elf(), "retail")
        linked = verifier.ELFImage(synthetic_elf(text=b"\x11\xff\x33\x44"), "linked")
        report = verifier.image_comparison(retail, linked, self._header())
        self.assertEqual(report["status"], "DIFFER")
        self.assertEqual(report["first_differing_offset"], 1)
        self.assertEqual(report["first_differing_address"], 0x1001)
        self.assertEqual(report["compared_bytes"], 4)

    def test_placed_rodata_is_compared(self):
        retail = verifier.ELFImage(synthetic_elf(rodata=b"\xa1\xb2"), "retail")
        linked = verifier.ELFImage(synthetic_elf(rodata=b"\xa1\xb3"), "linked")
        report = verifier.image_comparison(retail, linked, self._header(rodata=0x1004))
        self.assertEqual(report["status"], "DIFFER")
        self.assertEqual(report["first_differing_address"], 0x1005)
        self.assertEqual(report["compared_bytes"], 6)

    def test_non_text_section_overlapping_claimed_span_is_refused(self):
        retail = verifier.ELFImage(synthetic_elf(), "retail")
        linked = verifier.ELFImage(
            synthetic_elf(rodata=b"\xaa\xbb", rodata_addr=0x1002), "linked"
        )
        with self.assertRaisesRegex(
            verifier.VerificationRefusal, "overlaps claimed span"
        ):
            verifier.image_comparison(retail, linked, self._header(rodata=0x1002))

    def test_artifact_and_rebuild_disagreement_is_reported(self):
        checks = {
            "artifact": {
                "status": "MATCH",
                "compared_bytes": 4,
                "differing_bytes": 0,
                "first_differing_address": None,
                "span_start": 0x1000,
                "regions": [
                    {"label": ".text", "actual_sha256": "artifact", "actual_bytes": 4}
                ],
            },
            "independent_rebuild": {
                "status": "DIFFER",
                "compared_bytes": 4,
                "differing_bytes": 1,
                "first_differing_address": 0x1001,
                "span_start": 0x1000,
                "regions": [
                    {"label": ".text", "actual_sha256": "rebuild", "actual_bytes": 4}
                ],
            },
        }
        status, disagreement, compared, offset, different = verifier.record_status(
            checks, "both"
        )
        self.assertEqual(status, "DIFFER")
        self.assertTrue(disagreement)
        self.assertEqual((compared, offset, different), (8, 1, 1))

    def test_equal_status_with_different_compared_bytes_is_reported(self):
        checks = {
            "artifact": {
                "status": "DIFFER",
                "compared_bytes": 4,
                "differing_bytes": 1,
                "first_differing_address": 0x1001,
                "span_start": 0x1000,
                "regions": [
                    {"label": ".text", "actual_sha256": "artifact", "actual_bytes": 4}
                ],
            },
            "independent_rebuild": {
                "status": "DIFFER",
                "compared_bytes": 4,
                "differing_bytes": 1,
                "first_differing_address": 0x1001,
                "span_start": 0x1000,
                "regions": [
                    {"label": ".text", "actual_sha256": "rebuild", "actual_bytes": 4}
                ],
            },
        }
        self.assertTrue(verifier.record_status(checks, "both")[1])

    def test_span_must_be_covered_by_contiguous_reviewed_functions(self):
        ranges = [(0x1000, 0x1004), (0x1004, 0x1008), (0x1010, 0x1014)]
        self.assertEqual(
            verifier.validate_reviewed_span(ranges, 0x1000, 0x1008), ranges[:2]
        )
        with self.assertRaises(verifier.VerificationRefusal):
            verifier.validate_reviewed_span([(0x1000, 0x1004)], 0x1000, 0x1008)
        with self.assertRaises(verifier.VerificationRefusal):
            verifier.validate_reviewed_span(ranges, 0x1000, 0x1009)

    def test_stale_linked_artifact_is_refused(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            source = root / "sample.c"
            source.write_text("source", encoding="utf-8")
            output = root / "output"
            output.mkdir()
            linked = output / "linked.elf"
            linked.write_bytes(synthetic_elf())
            now = 1_800_000_000
            os.utime(source, (now + 2, now + 2))
            os.utime(linked, (now, now))
            with self.assertRaisesRegex(
                verifier.VerificationRefusal, "older than its source"
            ):
                verifier.check_artifact(
                    output,
                    source,
                    verifier.ELFImage(synthetic_elf(), "retail"),
                    self._header(),
                )


if __name__ == "__main__":
    unittest.main()
