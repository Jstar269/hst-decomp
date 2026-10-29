/* HSTMATCH module=hstp_trans_main.prx start=0x001c1138 end=0x001c1198 symbol=FUN_001c1138 lang=c99 */
/* Clone of src/eboot/FUN_001b3008.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00063304();

/* Release the two slot objects (slot 4 and slot 173), clearing each slot. */
void FUN_001c1138(SlotTable **ref)
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
      FUN_00063304(obj,1);
      table->slot[173] = 0;
    }
  }
  if ((table->slot[4] != 0) && (table->slot[4] != 0)) {
    FUN_00063304(table->slot[4],1);
    table->slot[4] = 0;
  }
}
