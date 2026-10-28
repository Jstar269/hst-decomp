/* HSTMATCH module=hstp_trans_main.prx start=0x0015827c end=0x00158308 symbol=FUN_0015827c lang=c99 */
/* Clone of src/eboot/FUN_0014c794.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0015b32c();
extern u32 * FUN_0015b528();

u32 * FUN_0015827c(u32 *param_1,u32 param_2,u32 param_3,u32 param_4)
{
  int *piVar1;
  u8 auStack_4 [4];
  u32 local_8;
  u32 *local_c;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = param_4;
  *(u8 *)(param_1 + 4) = 0;
  FUN_0015b528(param_1 + 6);
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    if (*piVar1 == 0) {
      param_1[5] = (unsigned int)(piVar1 + 1);
    }
    else {
      param_1[5] = piVar1[2];
    }
  }
  local_c = param_1 + 7;
  local_8 = param_1[8];
  FUN_0015b32c(auStack_4,param_1 + 6,&local_8,&local_c);
  return param_1;
}
