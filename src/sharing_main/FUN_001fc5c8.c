/* HSTMATCH module=hstp_trans_main.prx start=0x001fc5c8 end=0x001fc5d8 symbol=FUN_001fc5c8 lang=c99 */
/* Clone of src/eboot/FUN_001ee200.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e19f0;

u32 FUN_001fc5c8(void)
{
  return *(u32 *)(DAT_003e19f0 + 0xa0);
}
