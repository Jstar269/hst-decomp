/* HSTMATCH module=EBOOT.BIN start=0x0008d298 end=0x0008d2ec symbol=FUN_0008d298 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void FUN_000114c0(void *, int, int);

/* Clears a Rec14 and sets its default bytes. */
Rec14 *FUN_0008d298(Rec14 *rec)
{
  FUN_000114c0(rec, 0, sizeof(Rec14));
  rec->unk00 = 0;
  rec->unk01 = 1;
  rec->unk02 = 2;
  rec->unk03 = 0;
  rec->unk09 = 0;
  rec->unk0a = 0;
  rec->unk10 = 0;
  return rec;
}
