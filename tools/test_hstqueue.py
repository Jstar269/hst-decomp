#!/usr/bin/env python3
"""Tests for hand-matching batch queue generator (hstqueue.py)."""
from __future__ import annotations

import hashlib
import json
import os
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hstattempts as A
import hstqueue as Q


class NearYieldAndFamilyRankTests(unittest.TestCase):
    def test_near_yield_computations(self) -> None:
        self.assertEqual(Q.near_yield(100, 4), 25.0)
        self.assertEqual(Q.near_yield(100, 0), 100.0)
        self.assertEqual(Q.near_yield(100, None), 0.0)

    def test_family_rank_thresholds(self) -> None:
        self.assertEqual(Q.family_rank(None), 0)
        self.assertEqual(Q.family_rank(0.95), 0)
        self.assertEqual(Q.family_rank(0.90), 0)
        self.assertEqual(Q.family_rank(0.89), 1)
        self.assertEqual(Q.family_rank(0.50), 1)
        self.assertEqual(Q.family_rank(0.49), 2)


class LoadExecutionRankTests(unittest.TestCase):
    def setUp(self) -> None:
        self.tmp = tempfile.TemporaryDirectory()
        self.tmp_path = Path(self.tmp.name)
        self.ledger_dir = self.tmp_path / "ledger"
        self.ledger_dir.mkdir(parents=True)
        self.ledger_raw = b'{"schema_version":1,"modules":[]}\n'
        (self.ledger_dir / "campaign.json").write_bytes(self.ledger_raw)
        self.ledger_sha256 = hashlib.sha256(self.ledger_raw).hexdigest()

        env = patch.dict(os.environ, {"HST_CAMPAIGN_ROOT": str(self.tmp_path)})
        env.start()
        self.addCleanup(env.stop)

    def tearDown(self) -> None:
        self.tmp.cleanup()

    def make_valid_doc(self) -> dict:
        return {
            "schema_version": 1,
            "ledger_sha256": self.ledger_sha256,
            "capture": {
                "source_commit": "a" * 40,
                "source_branch": "main",
                "trace_kind": "trace-window-v1",
                "trace_sha256": "b" * 64,
                "scope": "bounded trace",
                "record_count": 10,
                "record_limit": 10,
                "complete": True,
                "unseen_is_not_zero_usage": True,
                "bringup": {
                    "failure_class": None,
                    "reached_stage": "done",
                    "presentation": {"frame_submissions": 60},
                },
            },
            "modules": [
                {
                    "name": "EBOOT.BIN",
                    "functions": [
                        {
                            "address": "0x00088000",
                            "execution_count": 5,
                            "code_bytes": 32,
                            "weighted_score": 160,
                        }
                    ],
                }
            ],
        }

    def test_load_valid_execution_rank(self) -> None:
        doc = self.make_valid_doc()
        path = self.tmp_path / "rank.json"
        path.write_text(json.dumps(doc), encoding="utf-8")

        result, capture = Q.load_execution_rank(path)
        self.assertIn("EBOOT.BIN", result)
        self.assertEqual(result["EBOOT.BIN"][0x88000]["execution_count"], 5)
        self.assertEqual(result["EBOOT.BIN"][0x88000]["weighted_score"], 160)
        self.assertEqual(capture["frame_submissions"], 60)

    def test_size_exceeded(self) -> None:
        path = self.tmp_path / "large.json"
        with patch.object(Path, "read_bytes", return_value=b"x" * (64 * 1024 * 1024 + 1)):
            with self.assertRaisesRegex(ValueError, "exceeds 64 MiB"):
                Q.load_execution_rank(path)

    def test_invalid_json(self) -> None:
        path = self.tmp_path / "bad.json"
        path.write_text("{invalid json", encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "cannot read execution rank"):
            Q.load_execution_rank(path)

    def test_schema_or_capture_errors(self) -> None:
        doc = self.make_valid_doc()
        path = self.tmp_path / "rank.json"

        # Bad schema version
        doc["schema_version"] = 2
        path.write_text(json.dumps(doc), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "unsupported execution-rank schema"):
            Q.load_execution_rank(path)

        # Incomplete capture
        doc = self.make_valid_doc()
        doc["capture"]["complete"] = False
        path.write_text(json.dumps(doc), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "not a complete bounded trace"):
            Q.load_execution_rank(path)

        # Missing unseen_is_not_zero_usage
        doc = self.make_valid_doc()
        doc["capture"]["unseen_is_not_zero_usage"] = False
        path.write_text(json.dumps(doc), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "unseen-function uncertainty"):
            Q.load_execution_rank(path)

        # Record count mismatch
        doc = self.make_valid_doc()
        doc["capture"]["record_count"] = 5
        path.write_text(json.dumps(doc), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "lacks its source, trace, or scope identity"):
            Q.load_execution_rank(path)

        # Frame submissions missing
        doc = self.make_valid_doc()
        doc["capture"]["bringup"]["presentation"]["frame_submissions"] = 0
        path.write_text(json.dumps(doc), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "no rendered frame submissions"):
            Q.load_execution_rank(path)

        # Ledger SHA mismatch
        doc = self.make_valid_doc()
        doc["ledger_sha256"] = "0" * 64
        path.write_text(json.dumps(doc), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "different campaign ledger"):
            Q.load_execution_rank(path)

    def test_module_and_function_row_errors(self) -> None:
        path = self.tmp_path / "rank.json"

        # Duplicate module
        doc = self.make_valid_doc()
        doc["modules"].append(doc["modules"][0])
        path.write_text(json.dumps(doc), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "repeats module"):
            Q.load_execution_rank(path)

        # Inconsistent weight score
        doc = self.make_valid_doc()
        doc["modules"][0]["functions"][0]["weighted_score"] = 999
        path.write_text(json.dumps(doc), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "inconsistent weights"):
            Q.load_execution_rank(path)

        # Duplicate function address in module
        doc = self.make_valid_doc()
        doc["modules"][0]["functions"].append(doc["modules"][0]["functions"][0])
        path.write_text(json.dumps(doc), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "repeats a function address"):
            Q.load_execution_rank(path)


class MainCLITests(unittest.TestCase):
    def setUp(self) -> None:
        self.tmp = tempfile.TemporaryDirectory()
        self.tmp_path = Path(self.tmp.name)
        env = patch.dict(os.environ, {"HST_CAMPAIGN_ROOT": str(self.tmp_path)})
        env.start()
        self.addCleanup(env.stop)

        self.ledger_dir = self.tmp_path / "ledger"
        self.ledger_dir.mkdir(parents=True)

        self.module_eboot = {
            "name": "EBOOT.BIN",
            "functions": [
                {"start": 0x88000, "end": 0x88040, "boundary_status": "reviewed"},
                {"start": 0x88040, "end": 0x88080, "boundary_status": "reviewed"},
                {"start": 0x88100, "end": 0x88180, "boundary_status": "reviewed"},
                {"start": 0x88200, "end": 0x882C0, "boundary_status": "reviewed"},
            ],
        }
        self.module_other = {
            "name": "hstp_trans_main.prx",
            "functions": [],
        }
        self.ledger = {"schema_version": 1, "modules": [self.module_eboot, self.module_other]}
        ledger_bytes = json.dumps(self.ledger).encode("utf-8")
        (self.ledger_dir / "campaign.json").write_bytes(ledger_bytes)
        self.campaign_sha256 = hashlib.sha256(ledger_bytes).hexdigest()

        # Functions 0 and 1 share bytes -> family of 2 members.
        # Functions 2 and 3 have unique bytes -> singles of 1 member each.
        raw_bytes = bytearray(0x10000)
        # func 0 and 1: byte 0x01
        for k in range(0, 0x80, 4):
            raw_bytes[k] = 0x01
        # func 2: byte 0x02
        for k in range(0x100, 0x180, 4):
            raw_bytes[k] = 0x02
        # func 3: byte 0x03
        for k in range(0x200, 0x2C0, 4):
            raw_bytes[k] = 0x03

        self.module_bytes_data = (bytes(raw_bytes), {"file_offset": 0, "start": 0x88000})

    def tearDown(self) -> None:
        self.tmp.cleanup()

    def test_missing_name_without_dry_run_raises(self) -> None:
        with patch.object(sys, "argv", ["hstqueue.py"]):
            with patch.object(sys, "stderr"):
                with self.assertRaises(SystemExit):
                    Q.main()

    def test_main_dry_run(self) -> None:
        with patch.object(sys, "argv", ["hstqueue.py", "--name", "testq", "--dry-run", "--min-start", "0x88000"]), \
             patch.object(Q.M, "ROOT", self.tmp_path), \
             patch.object(Q.M, "module_bytes", return_value=self.module_bytes_data), \
             patch.object(A, "collect", return_value=A.Attempts({}, {}, {}, {}, {})), \
             patch.object(Q.G, "load_pseudocode", return_value=({}, {})):
            ret = Q.main()
            self.assertEqual(ret, 0)

    def test_main_writes_agent_queue_batch(self) -> None:
        agent_queue_dir = self.tmp_path / "try" / "agent-queue"
        agent_queue_dir.mkdir(parents=True, exist_ok=True)

        with patch.object(sys, "argv", ["hstqueue.py", "--name", "mybatch", "--min-start", "0x88000", "--per-batch", "2", "--batches", "1"]), \
             patch.object(Q.M, "ROOT", self.tmp_path), \
             patch.object(Q.M, "module_bytes", return_value=self.module_bytes_data), \
             patch.object(A, "collect", return_value=A.Attempts({}, {}, {}, {}, {})), \
             patch.object(Q.G, "load_pseudocode", return_value=({0x88000: ("FUN_00088000", "int code();")}, {})):
            ret = Q.main()
            self.assertEqual(ret, 0)

            out_file = agent_queue_dir / "mybatch-00.json"
            self.assertTrue(out_file.exists())
            doc = json.loads(out_file.read_text(encoding="utf-8"))
            self.assertEqual(doc["module"], "EBOOT.BIN")
            self.assertEqual(doc["kind"], "families")
            self.assertGreater(len(doc["items"]), 0)
            item = doc["items"][0]
            self.assertEqual(item["address"], "0x00088000")
            self.assertEqual(item["ghidra_name"], "FUN_00088000")
            self.assertEqual(item["pseudocode"], "int code();")

    def test_main_existing_queue_raises_system_exit(self) -> None:
        agent_queue_dir = self.tmp_path / "try" / "agent-queue"
        agent_queue_dir.mkdir(parents=True, exist_ok=True)
        (agent_queue_dir / "dup-00.json").write_text("{}", encoding="utf-8")

        with patch.object(sys, "argv", ["hstqueue.py", "--name", "dup", "--min-start", "0x88000"]), \
             patch.object(Q.M, "ROOT", self.tmp_path):
            with self.assertRaises(SystemExit) as cm:
                Q.main()
            self.assertIn("queue dup exists", str(cm.exception))

    def test_main_singles_kind(self) -> None:
        agent_queue_dir = self.tmp_path / "try" / "agent-queue"
        agent_queue_dir.mkdir(parents=True, exist_ok=True)

        with patch.object(sys, "argv", ["hstqueue.py", "--name", "singlesbatch", "--kind", "singles", "--min-start", "0x88000"]), \
             patch.object(Q.M, "ROOT", self.tmp_path), \
             patch.object(Q.M, "module_bytes", return_value=self.module_bytes_data), \
             patch.object(A, "collect", return_value=A.Attempts({}, {}, {}, {}, {})), \
             patch.object(Q.G, "load_pseudocode", return_value=({}, {})):
            ret = Q.main()
            self.assertEqual(ret, 0)
            out_file = agent_queue_dir / "singlesbatch-00.json"
            self.assertTrue(out_file.exists())
            doc = json.loads(out_file.read_text(encoding="utf-8"))
            self.assertEqual(doc["kind"], "singles")

    def test_main_lanes_dealing(self) -> None:
        agent_queue_dir = self.tmp_path / "try" / "agent-queue"
        agent_queue_dir.mkdir(parents=True, exist_ok=True)

        with patch.object(sys, "argv", ["hstqueue.py", "--name", "laneq", "--lanes", "2", "--lane-size", "1", "--min-start", "0x88000"]), \
             patch.object(Q.M, "ROOT", self.tmp_path), \
             patch.object(Q.M, "module_bytes", return_value=self.module_bytes_data), \
             patch.object(A, "collect", return_value=A.Attempts({}, {}, {}, {}, {})), \
             patch.object(Q.G, "load_pseudocode", return_value=({}, {})):
            ret = Q.main()
            self.assertEqual(ret, 0)
            self.assertTrue((agent_queue_dir / "laneq1-00.json").exists())
            self.assertTrue((agent_queue_dir / "laneq2-00.json").exists())

    def test_main_with_execution_rank(self) -> None:
        agent_queue_dir = self.tmp_path / "try" / "agent-queue"
        agent_queue_dir.mkdir(parents=True, exist_ok=True)

        rank_file = self.tmp_path / "exec_rank.json"
        rank_doc = {
            "schema_version": 1,
            "ledger_sha256": self.campaign_sha256,
            "capture": {
                "source_commit": "a" * 40,
                "trace_sha256": "b" * 64,
                "scope": "test",
                "record_count": 1,
                "record_limit": 1,
                "complete": True,
                "unseen_is_not_zero_usage": True,
                "bringup": {"presentation": {"frame_submissions": 1}},
            },
            "modules": [{
                "name": "EBOOT.BIN",
                "functions": [{
                    "address": "0x00088000",
                    "execution_count": 10,
                    "code_bytes": 64,
                    "weighted_score": 640,
                }],
            }],
        }
        rank_file.write_text(json.dumps(rank_doc), encoding="utf-8")

        with patch.object(sys, "argv", ["hstqueue.py", "--name", "execbatch", "--execution-rank", str(rank_file), "--min-start", "0x88000"]), \
             patch.object(Q.M, "ROOT", self.tmp_path), \
             patch.object(Q.M, "module_bytes", return_value=self.module_bytes_data), \
             patch.object(A, "collect", return_value=A.Attempts({}, {}, {}, {}, {})), \
             patch.object(Q.G, "load_pseudocode", return_value=({}, {})):
            ret = Q.main()
            self.assertEqual(ret, 0)
            out_file = agent_queue_dir / "execbatch-00.json"
            self.assertTrue(out_file.exists())
            doc = json.loads(out_file.read_text(encoding="utf-8"))
            self.assertIn("execution_capture", doc)
            item = doc["items"][0]
            self.assertIn("execution_weight", item)
            self.assertEqual(item["execution_weight"]["entry_hits_in_window"], 10)


if __name__ == "__main__":
    unittest.main()
