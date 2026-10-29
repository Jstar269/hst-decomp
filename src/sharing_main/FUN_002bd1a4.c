/* HSTMATCH module=hstp_trans_main.prx start=0x002bd1a4 end=0x002bd218 symbol=FUN_002bd1a4 lang=c99 */
/* Clone of src/eboot/FUN_002ad9e8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/item_table.h"

extern u8 DAT_003f4830;
extern int DAT_003f48d0;
extern ItemTable * FUN_00177d4c();
extern void FUN_001cd870();

/* Hand every queued record index to the record handler with value 4, then empty the queue. */
void FUN_002bd1a4(void)
{
  ItemTable *table;
  int i;
  u32 *queued;
  
  i = 0;
  if (0 < DAT_003f48d0) {
    queued = (u32 *)&DAT_003f4830;
    do {
      table = FUN_00177d4c();
      FUN_001cd870(table,*queued,4);
      i = i + 1;
      queued = queued + 1;
    } while (i < DAT_003f48d0);
  }
  DAT_003f48d0 = 0;
  return;
}
