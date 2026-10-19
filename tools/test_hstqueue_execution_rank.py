#!/usr/bin/env python3
"""Synthetic tests for execution-weighted queue ordering."""
from __future__ import annotations

import unittest
from pathlib import Path
import hashlib
import json
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstqueue


class ExecutionQueueOrderTests(unittest.TestCase):
    def test_unattended_lane_rank_is_explicitly_opt_in(self) -> None:
        tools_dir = Path(__file__).resolve().parent
        auto = (tools_dir / "hstauto.sh").read_text(encoding="utf-8")
        supervisor = (tools_dir / "hstsupervise.sh").read_text(encoding="utf-8")
        self.assertIn('"${HST_USE_EXECUTION_RANK:-0}" = 1', auto)
        self.assertIn('HST_USE_EXECUTION_RANK="${HST_SUPERVISE_EXECUTION_RANK:-0}"', supervisor)

    def test_observed_score_leads_and_unseen_rows_keep_legacy_order(self) -> None:
        rows = [
            {"legacy_priority": -1000, "tie_size": 4, "execution_count": 0, "execution_score": 0,
             "name": "large-but-unseen"},
            {"legacy_priority": -5, "tie_size": 12, "execution_count": 2, "execution_score": 24,
             "name": "observed-24"},
            {"legacy_priority": -10, "tie_size": 8, "execution_count": 3, "execution_score": 30,
             "name": "observed-30"},
            {"legacy_priority": -100, "tie_size": 4, "execution_count": 0, "execution_score": 0,
             "name": "small-unseen"},
        ]
        ordered = sorted(rows, key=lambda row: hstqueue._execution_queue_key(row, True))
        self.assertEqual([row["name"] for row in ordered], [
            "observed-30", "observed-24", "large-but-unseen", "small-unseen"
        ])

    def test_default_order_is_unchanged_without_a_rank_file(self) -> None:
        rows = [
            {"legacy_priority": (1, 0.4), "tie_size": 8, "execution_count": 100,
             "execution_score": 800, "name": "legacy-later"},
            {"legacy_priority": (0, 0.9), "tie_size": 4, "execution_count": 1,
             "execution_score": 4, "name": "legacy-first"},
        ]
        ordered = sorted(rows, key=lambda row: hstqueue._execution_queue_key(row, False))
        self.assertEqual([row["name"] for row in ordered], ["legacy-first", "legacy-later"])

    def test_rank_loader_binds_weights_to_the_exact_ledger(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            ledger_dir = root / "ledger"
            ledger_dir.mkdir()
            ledger_raw = b'{"schema_version":1,"modules":[]}\n'
            (ledger_dir / "campaign.json").write_bytes(ledger_raw)
            original_campaign = hstqueue.M.CAMPAIGN
            hstqueue.M.CAMPAIGN = root
            try:
                rank_path = root / "rank.json"
                document = {
                    "schema_version": 1,
                    "ledger_sha256": hashlib.sha256(ledger_raw).hexdigest(),
                    "capture": {
                        "source_commit": "a" * 40,
                        "trace_kind": "trace-window-v1",
                        "trace_sha256": "b" * 64,
                        "scope": "synthetic bounded trace",
                        "record_count": 2,
                        "record_limit": 2,
                        "complete": True,
                        "unseen_is_not_zero_usage": True,
                        "bringup": {"failure_class": "synthetic", "presentation": {"frame_submissions": 1}},
                    },
                    "modules": [{
                        "name": "EBOOT.BIN",
                        "functions": [{
                            "address": "0x00001000", "code_bytes": 8,
                            "execution_count": 2, "weighted_score": 16,
                        }],
                    }],
                }
                rank_path.write_text(json.dumps(document), encoding="utf-8")
                ranks, capture = hstqueue.load_execution_rank(rank_path)
                self.assertEqual(ranks["EBOOT.BIN"][0x1000]["weighted_score"], 16)
                self.assertTrue(capture["unseen_is_not_zero_usage"])
                self.assertEqual(capture["frame_submissions"], 1)
                document["capture"]["bringup"]["presentation"]["frame_submissions"] = 0
                rank_path.write_text(json.dumps(document), encoding="utf-8")
                with self.assertRaisesRegex(ValueError, "no rendered frame submissions"):
                    hstqueue.load_execution_rank(rank_path)
                document["capture"]["bringup"]["presentation"]["frame_submissions"] = 1
                document["ledger_sha256"] = "0" * 64
                rank_path.write_text(json.dumps(document), encoding="utf-8")
                with self.assertRaisesRegex(ValueError, "different campaign ledger"):
                    hstqueue.load_execution_rank(rank_path)
            finally:
                hstqueue.M.CAMPAIGN = original_campaign


if __name__ == "__main__":
    unittest.main()
