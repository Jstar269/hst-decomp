/* HSTMATCH module=EBOOT.BIN start=0x001b3a0c end=0x001b3b34 symbol=FUN_001b3a0c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: combined the range and slot-present tests and stored the incoming mode value; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00062418();
extern void FUN_001b0ef8();

#define SLOT_MODE_VARIANT 6 /* mode that selects the single-object layout */

/* Switch the table to a new mode: release the old mode's slot (when asked) and load the new mode's slots. */
void FUN_001b3a0c(SlotTable **ref,int mode,int flag)
{
  int in_range;
  int slot_id;
  SlotTable *table;
  void **entry;
  void *obj;

  table = *ref;
  if ((table->unk7a4 >= 0) && (flag != 0)) {
    slot_id = table->unk7a4 + 0x28;
    in_range = (slot_id < SLOT_COUNT) && (table->slot[slot_id] != 0);
    if (in_range) {
      entry = &table->slot[slot_id];
      obj = *entry;
      if (obj != 0) {
        FUN_00062418(obj,1);
        *entry = 0;
      }
    }
  }
  FUN_001b0ef8(table,mode + 0x28,flag,0,0);
  FUN_001b0ef8(table,mode + 0x84,0,0,0);
  if (mode == SLOT_MODE_VARIANT) {
    FUN_001b0ef8(table,0x81,0,0,0);
    table->unk7a4 = mode;
  }
  else {
    FUN_001b0ef8(table,mode * 2 + 0x98,0,0,0);
    FUN_001b0ef8(table,mode * 2 + 0x99,0,0,0);
    table->unk7a4 = mode;
  }
}
