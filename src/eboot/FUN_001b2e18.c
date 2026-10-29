/* HSTMATCH module=EBOOT.BIN start=0x001b2e18 end=0x001b2e78 symbol=FUN_001b2e18 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00062418();

/* Release the objects held in slots 0xac and 0xad. */
void FUN_001b2e18(SlotTable **ref)
{
  SlotTable *table;
  void *obj;
  
  table = *ref;
  obj = table->slot[0xac];
  if (obj == 0) {
    obj = table->slot[0xad];
  }
  else {
    if (obj != 0) {
      FUN_00062418(obj,1);
      table->slot[0xac] = 0;
    }
  }
  if (((table->slot[0xad]) != 0) && ((table->slot[0xad]) != 0)) {
    FUN_00062418((table->slot[0xad]),1);
    table->slot[0xad] = 0;
  }
}
