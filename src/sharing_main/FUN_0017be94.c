/* HSTMATCH module=hstp_trans_main.prx start=0x0017be94 end=0x0017bef0 symbol=FUN_0017be94 lang=c99 */
/* Clone of src/eboot/FUN_0016fc48.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/table_page.h"

/* Copies each slot's byte value into byte 1 of its entry record. */
void FUN_0017be94(TablePage *self)
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
