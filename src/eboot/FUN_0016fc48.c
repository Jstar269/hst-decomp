/* HSTMATCH module=EBOOT.BIN start=0x0016fc48 end=0x0016fca4 symbol=FUN_0016fc48 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants), on a variant refined by hstperm.py random mutation (perm-p1/r00/f0404_0016fc48_m02.c); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/table_page.h"

/* Copies each slot's byte value into byte 1 of its entry record. */
void FUN_0016fc48(TablePage *self)
{
  int record;
  int slot;
  
  slot = 0;
  do {
    record = self->getEntry(slot);
    *(char *)(record + 1) = (char)self->byteValues[slot];
    slot = slot + 1;
  } while (slot < TABLE_PAGE_SLOTS);
}
