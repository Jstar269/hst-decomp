/* HSTMATCH module=EBOOT.BIN start=0x001bf9f0 end=0x001bfa44 symbol=FUN_001bf9f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/item_table.h"

extern void FUN_001bbd30();

/* Pass record `index` of the table (if in range) to the record handler with `value`. */
void FUN_001bf9f0(ItemTable *table,int index,u32 value)
{
  ItemRecord *record;
  
  if (index >= 0 && (index < ITEM_RECORD_COUNT)) {
    record = &table->record[index];
  }
  else {
    record = 0;
  }
  if (record != 0) {
    FUN_001bbd30(record,value,0);
  }
}
