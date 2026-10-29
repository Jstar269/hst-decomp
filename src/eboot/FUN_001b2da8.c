/* HSTMATCH module=EBOOT.BIN start=0x001b2da8 end=0x001b2de8 symbol=FUN_001b2da8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00062418();

/* Release the object held in slot 0xb0. */
void FUN_001b2da8(SlotTable **ref)
{
  void *obj;
  SlotTable *table;
  
  table = *ref;
  obj = table->slot[0xb0];
  if ((obj != 0) && (obj != 0)) {
    FUN_00062418(obj,1);
    table->slot[0xb0] = 0;
  }
}
