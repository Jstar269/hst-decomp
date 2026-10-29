/* HSTMATCH module=hstp_trans_main.prx start=0x0017bef0 end=0x0017bf54 symbol=FUN_0017bef0 lang=c99 */
/* Clone of src/eboot/FUN_0016fca4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/table_page.h"

/* When the page is active, copies each slot's short value into halfword 1 of its entry record. */
void FUN_0017bef0(TablePage *self)
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
