/* HSTMATCH module=hstp_trans_main.prx start=0x0020c9c4 end=0x0020ca14 symbol=FUN_0020c9c4 lang=c99 */
/* Clone of src/eboot/FUN_001fe1f4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0020c9c4(u32 *param_1)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    *param_1 = 0x7fffffff;
    *(u8 *)(param_1 + 1) = 0;
    *(u8 *)((int)param_1 + 5) = 0;
    *(u8 *)((int)param_1 + 6) = 0;
    *(u8 *)((int)param_1 + 7) = 0;
    param_1[2] = 0x7fffffff;
    param_1[3] = 0x7fffffff;
    param_1[4] = 0x7fffffff;
    param_1[5] = 0x7fffffff;
    param_1[6] = 0x7fffffff;
    iVar1 = iVar1 + 1;
    param_1[7] = 0x7fffffff;
    param_1 = param_1 + 8;
  } while (iVar1 < 10);
}
