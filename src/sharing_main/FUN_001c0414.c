/* HSTMATCH module=hstp_trans_main.prx start=0x001c0414 end=0x001c0454 symbol=FUN_001c0414 lang=c99 */
/* Clone of src/eboot/FUN_001b2380.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001be964();
extern void FUN_001bf834();

/* Load the kept slot, then run the table's follow-up step. */
void FUN_001c0414(SlotTable **ref)
{
  SlotTable *table;
  
  table = *ref;
  FUN_001be964(table,SLOT_KEEP,0,0,0);
  FUN_001bf834(table);
}
