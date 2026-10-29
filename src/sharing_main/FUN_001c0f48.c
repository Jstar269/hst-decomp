/* HSTMATCH module=hstp_trans_main.prx start=0x001c0f48 end=0x001c0fa8 symbol=FUN_001c0f48 lang=c99 */
/* Clone of src/eboot/FUN_001b2e18.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00063304();

/* Release the objects held in slots 0xac and 0xad. */
void FUN_001c0f48(SlotTable **ref)
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
      FUN_00063304(obj,1);
      table->slot[0xac] = 0;
    }
  }
  if (((table->slot[0xad]) != 0) && ((table->slot[0xad]) != 0)) {
    FUN_00063304((table->slot[0xad]),1);
    table->slot[0xad] = 0;
  }
}
