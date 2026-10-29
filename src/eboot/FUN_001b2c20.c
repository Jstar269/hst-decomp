/* HSTMATCH module=EBOOT.BIN start=0x001b2c20 end=0x001b2c70 symbol=FUN_001b2c20 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001b0ef8();

/* Load slots 0 and 0xb2. */
void FUN_001b2c20(SlotTable **ref)
{
  SlotTable *table;
  
  table = *ref;
  FUN_001b0ef8(table,0,0,0,0);
  FUN_001b0ef8(table,0xb2,0,0,0);
}
