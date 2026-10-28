/* HSTMATCH module=hstp_trans_main.prx start=0x00054130 end=0x000541d8 symbol=FUN_00054130 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00054260();
extern u32 FUN_0005427c();

int FUN_00054130(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7)
{
  *(u32 *)(param_1 + 0x18) = 0;
  *(u32 *)(param_1 + 0x1c) = 0;
  *(u32 *)(param_1 + 0x20) = 0;
  *(u32 *)(param_1 + 0x24) = 0;
  *(u32 *)(param_1 + 0x28) = 0;
  *(u32 *)(param_1 + 0x2c) = 0;
  FUN_00054260();
  FUN_0005427c(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return param_1;
}
