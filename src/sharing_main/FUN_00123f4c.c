/* HSTMATCH module=hstp_trans_main.prx start=0x00123f4c end=0x00123fb4 symbol=FUN_00123f4c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0320_00123f4c_m01.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00123668();
extern u32 FUN_00123fb4();
extern u32 * FUN_00124130();
extern u32 FUN_00124148();

int FUN_00123f4c(int param_1,u32 param_2)
{
  u8 auStack_4 [4];
  u32 uVar1;
  u8 auStack_14 [16];
  
  uVar1 = FUN_00124148(auStack_4);
  FUN_00124130(auStack_14,uVar1);
  FUN_00123fb4(param_1,param_2,auStack_14);
  FUN_00123668(auStack_14,0xffffffff);
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
