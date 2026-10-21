#!/usr/bin/env python3
"""Synthetic tests for the compiler-family predictor (hstfamily.py): feature extraction and the learner."""
from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstfamily as F


def i_type(op: int, rs: int, rt: int, imm: int) -> int:
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


ADDIU, SW, LW = 0x09, 0x2B, 0x23
SP, RA = 29, 31


class FeatureTests(unittest.TestCase):
    def test_metrowerks_style_saves_ra_at_the_frame_top(self) -> None:
        ws = [i_type(ADDIU, SP, SP, -32), i_type(SW, SP, RA, 28), i_type(SW, SP, 16, 24), 0x03E00008, i_type(ADDIU, SP, SP, 32)]
        f = F.code_features(ws)
        self.assertEqual((f["has_frame"], f["frame_mult16"], f["ra_saved"], f["ra_at_top"]), (1.0, 1.0, 1.0, 1.0))
        self.assertEqual(f["jr_ra_count"], 1.0)

    def test_gcc_style_frame_and_jumps(self) -> None:
        ws = [i_type(ADDIU, SP, SP, -24), i_type(SW, SP, RA, 16), (2 << 26) | 0x100, 0, 0x03E00008, i_type(ADDIU, SP, SP, 24)]
        f = F.code_features(ws)
        self.assertEqual((f["frame_mult16"], f["frame_mult8_only"], f["ra_at_top"]), (0.0, 1.0, 0.0))
        self.assertGreater(f["j_rate"], 0.0)
        self.assertGreater(f["nop_rate"], 0.0)

    def test_branch_likely_and_at_compare_are_counted(self) -> None:
        slt_at = (8 << 21) | (9 << 16) | (1 << 11) | 0x2A               # slt at, t0, t1
        beql = i_type(0x14, 1, 0, 3)
        f = F.code_features([slt_at, beql, 0])
        self.assertGreater(f["likely_rate"], 0.0)
        self.assertGreater(f["slt_at"], 0.0)
        self.assertGreater(f["t_rate"], 0.0)

    def test_address_features_split_at_the_sdk_boundary(self) -> None:
        self.assertEqual(F.address_features(0x1000), {"addr_low": 1.0, "addr_vlow": 1.0})
        self.assertEqual(F.address_features(0x90000), {"addr_low": 0.0, "addr_vlow": 0.0})


class LearnerTests(unittest.TestCase):
    def test_logistic_separates_a_toy_set_and_auc_is_one(self) -> None:
        rows = []
        for k in range(60):
            feat = dict.fromkeys(F.FEATURES, 0.0)
            label = k % 2
            feat["ra_at_top"] = float(label)
            feat["j_rate"] = 0.2 * (1 - label)
            rows.append(F.Fn("EBOOT.BIN", k * 4, k * 4 + 4, label, feat, str(k)))
        model = F.Logistic(["ra_at_top", "j_rate"])
        model.fit(rows)
        pairs = [(r.label, model.prob(r.feat)) for r in rows]
        self.assertEqual(F.auc(pairs), 1.0)
        self.assertEqual(F.metrics(pairs)["accuracy"], 1.0)

    def test_metrics_confusion(self) -> None:
        m = F.metrics([(1, 0.9), (1, 0.4), (0, 0.6), (0, 0.1)])
        self.assertEqual(m["confusion"], {"tp": 1, "fn": 1, "fp": 1, "tn": 1})
        self.assertEqual(m["accuracy"], 0.5)


if __name__ == "__main__":
    unittest.main()
