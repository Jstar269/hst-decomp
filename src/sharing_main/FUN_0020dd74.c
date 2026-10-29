/* HSTMATCH module=hstp_trans_main.prx start=0x0020dd74 end=0x0020dda0 symbol=FUN_0020dd74 lang=c99 */
/* Clone of src/eboot/FUN_001ff5a4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/record_bank.h"

extern RecordRoot * DAT_003e1a08;
extern void FUN_00292408();

/* Pass the record owner on to FUN_00292408 when the root exists. */
void FUN_0020dd74(void)
{
  if (DAT_003e1a08 != 0) {
    FUN_00292408(DAT_003e1a08->owner);
  }
}
