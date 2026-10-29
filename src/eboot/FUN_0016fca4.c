/* HSTMATCH module=EBOOT.BIN start=0x0016fca4 end=0x0016fd08 symbol=FUN_0016fca4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants), on a variant refined by hstperm.py random mutation (perm-p1/r00/f0405_0016fca4_m04.c); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/table_page.h"

/* When the page is active, copies each slot's short value into halfword 1 of its entry record. */
void FUN_0016fca4(TablePage *self)
{
  u32 record;
  int slot;
  
  if (self->active != '\0') {
    slot = 0;
    do {
      record = self->getEntry(slot);
      *(short *)(record + 2) = (short)self->shortValues[slot];
      slot = slot + 1;
    } while (slot < TABLE_PAGE_SLOTS);
  }
}
