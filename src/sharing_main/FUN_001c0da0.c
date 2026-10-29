/* HSTMATCH module=hstp_trans_main.prx start=0x001c0da0 end=0x001c0e00 symbol=FUN_001c0da0 lang=c99 */
/* Clone of src/eboot/FUN_001b2c70.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00063304();

/* Release the objects held in slots 0xb2 and 0. */
void FUN_001c0da0(SlotTable **ref)
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
      FUN_00063304(obj,1);
      table->slot[0xb2] = 0;
    }
  }
  if (((table->slot[0]) != 0) && ((table->slot[0]) != 0)) {
    FUN_00063304((table->slot[0]),1);
    table->slot[0] = 0;
  }
}
