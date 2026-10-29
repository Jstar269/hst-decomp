/* HSTMATCH module=EBOOT.BIN start=0x001b2cd0 end=0x001b2d88 symbol=FUN_001b2cd0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: matched the status return type and branch polarity; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001b0ef8();
extern int FUN_0022c988();

/* Load slot 1 (with the caller's argument), pick slot 0xaf or 0xae by a mode query and make it the current state, then load slots 0x3e and 0x53. */
void FUN_001b2cd0(SlotTable **ref,u32 arg)
{
  SlotTable *table;
  
  table = *ref;
  FUN_001b0ef8(table,1,0,arg,0);
  if (FUN_0022c988(8) != 0) {
    FUN_001b0ef8(table,0xaf,0,0,0);
    table->cur = 0xaf;
  }
  else {
    FUN_001b0ef8(table,0xae,0,0,0);
    table->cur = 0xae;
  }
  FUN_001b0ef8(table,0x3e,0,0,0);
  FUN_001b0ef8(table,0x53,0,0,0);
}
