/* HSTMATCH module=hstp_trans_main.prx start=0x001c0fa8 end=0x001c1010 symbol=FUN_001c0fa8 lang=c99 */
/* Clone of src/eboot/FUN_001b2e78.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001be964();

/* Load slots 0xac, 0x3e and 0x3f. */
void FUN_001c0fa8(SlotTable **ref)
{
  SlotTable *table;
  
  table = *ref;
  FUN_001be964(table,0xac,0,0,0);
  FUN_001be964(table,0x3e,0,0,0);
  FUN_001be964(table,0x3f,0,0,0);
}
