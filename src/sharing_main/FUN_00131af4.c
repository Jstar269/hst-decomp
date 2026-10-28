/* HSTMATCH module=hstp_trans_main.prx start=0x00131af4 end=0x00131b28 symbol=FUN_00131af4 lang=c99 */
/* Clone of src/eboot/FUN_00126884.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00104f10();

void FUN_00131af4(int param_1,u32 param_2,u32 *param_3)
{
  u32 uVar1;
  
  uVar1 = FUN_00104f10(*(u32 *)(param_1 + 0x1c),param_2,*param_3,0);
  *param_3 = uVar1;
}
