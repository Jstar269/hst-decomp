/* HSTMATCH module=EBOOT.BIN start=0x001aff8c end=0x001affe4 symbol=FUN_001aff8c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001b052c(SlotTable *, int);
extern void FUN_001b0610(SlotTable *, int);

void FUN_001aff8c(SlotTable *self)
{
  FUN_001b0610(self,0);
  FUN_001b052c(self,3);
  FUN_001b052c(self,2);
  FUN_001b052c(self,1);
  FUN_001b052c(self,0);
}
