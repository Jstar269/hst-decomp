/* HSTMATCH module=hstp_trans_main.prx start=0x002bf720 end=0x002bf730 symbol=FUN_002bf720 lang=c99 */
/* Clone of src/eboot/FUN_002afcd0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f4918;

u8 FUN_002bf720(void)
{
  return *(u8 *)(DAT_003f4918 + 0x168);
}
