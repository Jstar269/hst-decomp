/* HSTMATCH module=EBOOT.BIN start=0x001afe0c end=0x001afe6c symbol=FUN_001afe0c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001b04d0(SlotTable *, int);

void FUN_001afe0c(SlotTable *self)
{
  self->cur = SLOT_COUNT;
  FUN_001b04d0(self,0x3e);
  FUN_001b04d0(self,0x53);
  FUN_001b04d0(self,0xaf);
  FUN_001b04d0(self,0xae);
  FUN_001b04d0(self,1);
}
