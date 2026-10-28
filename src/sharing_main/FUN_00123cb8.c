/* HSTMATCH module=hstp_trans_main.prx start=0x00123cb8 end=0x00123d20 symbol=FUN_00123cb8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r01/f0309_00123cb8_m06.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_001235a0();
extern u32 FUN_00123d20();
extern u32 * FUN_00123e9c();
extern u32 FUN_00123eb4();

int FUN_00123cb8(int param_1,u32 param_2)
{
  u32 uVar1;
  u8 auStack_4 [4];
  u8 auStack_14 [16];
  
  uVar1 = FUN_00123eb4(auStack_4);
  FUN_00123e9c(auStack_14,uVar1);
  FUN_00123d20(param_1,param_2,auStack_14);
  FUN_001235a0(auStack_14,0xffffffff);
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
