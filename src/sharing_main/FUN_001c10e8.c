/* HSTMATCH module=hstp_trans_main.prx start=0x001c10e8 end=0x001c1138 symbol=FUN_001c10e8 lang=c99 */
/* Clone of src/eboot/FUN_001b2fb8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001be964();

/* Load slots 4 and 0xad. */
void FUN_001c10e8(SlotTable **ref)
{
  SlotTable *table;
  
  table = *ref;
  FUN_001be964(table,4,0,0,0);
  FUN_001be964(table,0xad,0,0,0);
}
