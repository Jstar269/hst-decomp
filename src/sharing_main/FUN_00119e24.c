/* HSTMATCH module=hstp_trans_main.prx start=0x00119e24 end=0x00119e58 symbol=FUN_00119e24 lang=c99 */
/* Clone of src/eboot/FUN_00111010.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003eaaac;
extern void FUN_00108aec();

void FUN_00119e24(void)
{
  *(u8 *)(DAT_003eaaac + 0x88) = 1;
  FUN_00108aec();
  *(u8 *)(DAT_003eaaac + 0x88) = 0;
}
