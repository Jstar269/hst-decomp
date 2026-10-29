/* HSTMATCH module=EBOOT.BIN start=0x0017df34 end=0x0017df44 symbol=FUN_0017df34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slot_mgr.h"

/* Set the flag at 0x41 and clear the word at 0x44. */
void FUN_0017df34(SlotMgr *self)
{
  self->unk41 = 1;
  self->unk44 = 0;
}
