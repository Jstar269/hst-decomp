/* HSTMATCH module=EBOOT.BIN start=0x0017de50 end=0x0017de58 symbol=FUN_0017de50 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slot_mgr.h"

/* Store the float at 0x34. */
void FUN_0017de50(float value,SlotMgr *self)
{
  self->unk34 = value;
  return;
}
