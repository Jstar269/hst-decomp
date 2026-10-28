/* HSTMATCH module=EBOOT.BIN start=0x00118d78 end=0x00118de0 symbol=FUN_00118d78 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0277_00118d78_m02.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00118494();
extern u32 FUN_00118de0();
extern u32 * FUN_00118f5c();
extern u32 FUN_00118f74();

int FUN_00118d78(int param_1,u32 param_2)
{
  u32 uVar1;
  u8 auStack_4 [4];
  u8 auStack_14 [16];
  
  uVar1 = FUN_00118f74(auStack_4);
  FUN_00118f5c(auStack_14,uVar1);
  FUN_00118de0(param_1,param_2,auStack_14);
  FUN_00118494(auStack_14,0xffffffff);
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
