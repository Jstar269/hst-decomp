/* HSTMATCH module=EBOOT.BIN start=0x001b2c70 end=0x001b2cd0 symbol=FUN_001b2c70 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00062418();

/* Release the objects held in slots 0xb2 and 0. */
void FUN_001b2c70(SlotTable **ref)
{
  void *obj;
  SlotTable *table;
  
  table = *ref;
  obj = table->slot[0xb2];
  if (obj == 0) {
    obj = table->slot[0];
  }
  else {
    if (obj != 0) {
      FUN_00062418(obj,1);
      table->slot[0xb2] = 0;
    }
  }
  if (((table->slot[0]) != 0) && ((table->slot[0]) != 0)) {
    FUN_00062418((table->slot[0]),1);
    table->slot[0] = 0;
  }
}
