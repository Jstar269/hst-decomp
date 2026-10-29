/* HSTMATCH module=EBOOT.BIN start=0x00261364 end=0x002613a0 symbol=FUN_00261364 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void * FUN_000114c0();

/* Clears the record, then marks its three halfword ids as unset. */
void FUN_00261364(Rec6c *rec)
{
  FUN_000114c0(rec,0,sizeof(Rec6c));
  rec->unk68 = 0xffff;
  rec->unk6a = 0xffff;
  rec->unk24 = 0xffff;
  return;
}
