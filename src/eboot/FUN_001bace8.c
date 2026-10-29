/* HSTMATCH module=EBOOT.BIN start=0x001bace8 end=0x001bad34 symbol=FUN_001bace8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/item_owner.h"

extern void FUN_00204c80();

/* Release item `index` and clear its flag bytes. */
void FUN_001bace8(ItemOwner *self,int index)
{
  FUN_00204c80(self->items[index]);
  self->unk10[index] = 0;
  self->unk14[index] = 0;
}
