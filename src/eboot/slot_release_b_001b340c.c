/* HSTMATCH module=EBOOT.BIN start=0x001b340c end=0x001b34b4 symbol=FUN_001b340c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py draft inputs/generated/FUN_001b340c.c) corrected by hand: single load of the 0x7a8 field, `idx >= 0` instead of `-1 < idx`, and the bounds test assigned to the bool before the short-circuit load; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00062418();
extern void FUN_001b0ef8();

/* Release the object of the previously selected entry, then select entry `index` and load its slot. */
void FUN_001b340c(SlotTable **ref,int index)
{
  bool in_range;
  int slot_id;
  SlotTable *table;
  void **entry;
  void *obj;

  table = *ref;
  if (table->unk7a8 >= 0) {
    slot_id = table->unk7a8 + 0xb4;
    in_range = slot_id < SLOT_COUNT;
    if (in_range) {
      in_range = table->slot[slot_id] != 0;
    }
    if (in_range) {
      entry = &table->slot[slot_id];
      obj = *entry;
      if (obj != 0) {
        FUN_00062418(obj,1);
        *entry = 0;
      }
    }
    table->unk7a8 = -1;
  }
  table->unk7a8 = index;
  FUN_001b0ef8(table,index + 0xb4,0,0,0);
}
