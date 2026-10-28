/* HSTMATCH module=hstp_trans_main.prx start=0x00105e6c end=0x00105eb8 symbol=FUN_00105e6c lang=c99 */
/* Clone of src/eboot/FUN_00100538.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00038258();

void FUN_00105e6c(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7)
{
  u32 uVar1;
  
  uVar1 = FUN_00038258(*(u32 *)(param_1 + 0x28),param_3,param_5,param_7,param_2,param_4,
                       param_6);
  *(u32 *)(param_1 + 0x28) = uVar1;
}
