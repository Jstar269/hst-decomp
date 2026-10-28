/* HSTMATCH module=EBOOT.BIN start=0x0018629c end=0x00186378 symbol=FUN_0018629c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0343_0018629c_m05.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00184afc();
extern void FUN_001851e0();
extern void FUN_00186d64();

void FUN_0018629c(int param_1,u32 param_2,u32 param_3,u32 param_4,int param_5, int param_6,u32 param_7,u32 param_8)
{
  u32 local_4;
  u32 local_8;
  
  if (param_6 != 0) {
    FUN_00186d64(param_1,param_3,param_4,param_5);
  }
  local_4 = 0;
  local_8 = 0;
  FUN_00184afc(param_1,&local_4,&local_8,param_2);
  FUN_001851e0(param_1,param_2,param_3,param_4,param_5,param_7,param_6,local_8,param_8);
  *(float *)(*(int *)(param_1 + 0x2860) + 0xe0) = (float)param_5;
}
