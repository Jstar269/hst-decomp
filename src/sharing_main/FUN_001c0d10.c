/* HSTMATCH module=hstp_trans_main.prx start=0x001c0d10 end=0x001c0d50 symbol=FUN_001c0d10 lang=c99 */
/* Clone of src/eboot/FUN_001b2be0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00063304();

/* Release the object held in slot 0x5b. */
void FUN_001c0d10(SlotTable **ref)
{
  void *obj;
  SlotTable *table;
  
  table = *ref;
  obj = table->slot[0x5b];
  if ((obj != 0) && (obj != 0)) {
    FUN_00063304(obj,1);
    table->slot[0x5b] = 0;
  }
}
