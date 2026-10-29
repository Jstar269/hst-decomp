/* HSTMATCH module=EBOOT.BIN start=0x001b2380 end=0x001b23c0 symbol=FUN_001b2380 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001b0ef8();
extern void FUN_001b1810();

/* Load the kept slot, then run the table's follow-up step. */
void FUN_001b2380(SlotTable **ref)
{
  SlotTable *table;
  
  table = *ref;
  FUN_001b0ef8(table,SLOT_KEEP,0,0,0);
  FUN_001b1810(table);
}
