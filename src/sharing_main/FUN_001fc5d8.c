/* HSTMATCH module=hstp_trans_main.prx start=0x001fc5d8 end=0x001fc5ec symbol=FUN_001fc5d8 lang=c99 */
/* Clone of src/eboot/FUN_001ee210.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e19f0;

int FUN_001fc5d8(void)
{
  return *(int *)(DAT_003e19f0 + 0xa0) + 0x54;
}
