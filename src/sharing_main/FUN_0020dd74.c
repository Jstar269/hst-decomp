/* HSTMATCH module=hstp_trans_main.prx start=0x0020dd74 end=0x0020dda0 symbol=FUN_0020dd74 lang=c99 */
/* Clone of src/eboot/FUN_001ff5a4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1a08;
extern void FUN_00292408();

void FUN_0020dd74(void)
{
  if (DAT_003e1a08 != 0) {
    FUN_00292408(*(u32 *)(DAT_003e1a08 + 0x40));
  }
}
