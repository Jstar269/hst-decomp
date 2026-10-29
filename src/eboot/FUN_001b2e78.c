/* HSTMATCH module=EBOOT.BIN start=0x001b2e78 end=0x001b2ee0 symbol=FUN_001b2e78 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001b0ef8();

/* Load slots 0xac, 0x3e and 0x3f. */
void FUN_001b2e78(SlotTable **ref)
{
  SlotTable *table;
  
  table = *ref;
  FUN_001b0ef8(table,0xac,0,0,0);
  FUN_001b0ef8(table,0x3e,0,0,0);
  FUN_001b0ef8(table,0x3f,0,0,0);
}
