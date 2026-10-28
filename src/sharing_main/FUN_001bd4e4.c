/* HSTMATCH module=hstp_trans_main.prx start=0x001bd4e4 end=0x001bd544 symbol=FUN_001bd4e4 lang=c99 */
/* Clone of src/eboot/FUN_001afe0c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern void FUN_001bde64(SlotTable *, int);

void FUN_001bd4e4(SlotTable *self)
{
  self->cur = SLOT_COUNT;
  FUN_001bde64(self,0x3e);
  FUN_001bde64(self,0x53);
  FUN_001bde64(self,0xaf);
  FUN_001bde64(self,0xae);
  FUN_001bde64(self,1);
}
