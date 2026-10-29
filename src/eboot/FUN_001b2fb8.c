/* HSTMATCH module=EBOOT.BIN start=0x001b2fb8 end=0x001b3008 symbol=FUN_001b2fb8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001b0ef8();

/* Load slots 4 and 0xad. */
void FUN_001b2fb8(SlotTable **ref)
{
  SlotTable *table;
  
  table = *ref;
  FUN_001b0ef8(table,4,0,0,0);
  FUN_001b0ef8(table,0xad,0,0,0);
}
