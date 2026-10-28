/* HSTMATCH module=EBOOT.BIN start=0x0008d1ec end=0x0008d22c symbol=FUN_0008d1ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void FUN_000114c0(void *, int, int);

/* Clears a Rec6c and sets its three halfword fields to -1. */
Rec6c *FUN_0008d1ec(Rec6c *rec)
{
  FUN_000114c0(rec, 0, sizeof(Rec6c));
  rec->unk68 = -1;
  rec->unk6a = -1;
  rec->unk24 = -1;
  return rec;
}
