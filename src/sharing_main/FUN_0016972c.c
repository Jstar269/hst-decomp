/* HSTMATCH module=hstp_trans_main.prx start=0x0016972c end=0x00169770 symbol=FUN_0016972c lang=c99 */
/* Clone of src/eboot/FUN_0015d184.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e9740;
extern u8 DAT_003ea34c;

void FUN_0016972c(u32 param_1,int param_2)
{
  u8 bVar1;
  
  (&DAT_003ea34c)[param_2] = 1;
  bVar1 = *(u8 *)(param_2 + DAT_003e9740 + 0x10);
  if (bVar1 < 0xc9) {
    *(u8 *)(param_2 + DAT_003e9740 + 0x10) = bVar1 + 1;
  }
}
