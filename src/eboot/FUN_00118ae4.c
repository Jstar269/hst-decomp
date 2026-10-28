/* HSTMATCH module=EBOOT.BIN start=0x00118ae4 end=0x00118b4c symbol=FUN_00118ae4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0276_00118ae4_m00.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_001183cc();
extern u32 FUN_00118b4c();
extern u32 * FUN_00118cc8();
extern u32 FUN_00118ce0();

int FUN_00118ae4(int param_1,u32 param_2)
{
  u32 uVar1;
  u8 auStack_4 [4];
  u8 auStack_14 [16];
  
  uVar1 = FUN_00118ce0(auStack_4);
  FUN_00118cc8(auStack_14,uVar1);
  FUN_00118b4c(param_1,param_2,auStack_14);
  FUN_001183cc(auStack_14,0xffffffff);
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
