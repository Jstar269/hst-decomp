/* HSTMATCH module=EBOOT.BIN start=0x002ad9e8 end=0x002ada5c symbol=FUN_002ad9e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/item_table.h"

extern u8 DAT_0034b4f0;
extern int DAT_0034b590;
extern ItemTable * FUN_0016bb88();
extern void FUN_001bf9f0();

/* Hand every queued record index to the record handler with value 4, then empty the queue. */
void FUN_002ad9e8(void)
{
  ItemTable *table;
  int i;
  u32 *queued;
  
  i = 0;
  if (0 < DAT_0034b590) {
    queued = (u32 *)&DAT_0034b4f0;
    do {
      table = FUN_0016bb88();
      FUN_001bf9f0(table,*queued,4);
      i = i + 1;
      queued = queued + 1;
    } while (i < DAT_0034b590);
  }
  DAT_0034b590 = 0;
  return;
}
