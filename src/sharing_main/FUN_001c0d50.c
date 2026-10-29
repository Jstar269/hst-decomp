/* HSTMATCH module=hstp_trans_main.prx start=0x001c0d50 end=0x001c0da0 symbol=FUN_001c0d50 lang=c99 */
/* Clone of src/eboot/FUN_001b2c20.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001be964();

/* Load slots 0 and 0xb2. */
void FUN_001c0d50(SlotTable **ref)
{
  SlotTable *table;
  
  table = *ref;
  FUN_001be964(table,0,0,0,0);
  FUN_001be964(table,0xb2,0,0,0);
}
