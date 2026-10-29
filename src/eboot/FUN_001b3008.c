/* HSTMATCH module=EBOOT.BIN start=0x001b3008 end=0x001b3068 symbol=FUN_001b3008 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00062418();

/* Release the two slot objects (slot 4 and slot 173), clearing each slot. */
void FUN_001b3008(SlotTable **ref)
{
  void *obj;
  SlotTable *table;

  table = *ref;
  obj = table->slot[173];
  if (obj == 0) {
    obj = table->slot[4];
  }
  else {
    if (obj != 0) {
      FUN_00062418(obj,1);
      table->slot[173] = 0;
    }
  }
  if ((table->slot[4] != 0) && (table->slot[4] != 0)) {
    FUN_00062418(table->slot[4],1);
    table->slot[4] = 0;
  }
}
