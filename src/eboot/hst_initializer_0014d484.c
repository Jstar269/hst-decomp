/* HSTMATCH module=EBOOT.BIN start=0x0014d484 end=0x0014d53c symbol=FUN_0014d484 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the loop counter is an unsigned local declared before the byte-offset local (counter s1, offset s0, sltiu); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00308360;
extern u8 DAT_0030840c;
extern u32 FUN_0014f028();
extern u32 FUN_0014f03c();
extern u16 FUN_0014f050();

#pragma opt_strength_reduction off

u32 * FUN_0014d484(u32 *param_1,u32 param_2)
{
  u32 uVar2;
  int r;
  u32 i;
  int off;
  
  *param_1 = (unsigned int)(&DAT_0030840c);
  *(u8 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_00308360);
  r = FUN_0014f050(param_2);
  param_1[2] = r & 0xffff;
  uVar2 = FUN_0014f03c(param_2);
  param_1[3] = uVar2;
  i = 0;
  off = 0;
  do {
    if (i < (u32)param_1[3]) {
      uVar2 = FUN_0014f028(param_2);
      *(u32 *)((int)param_1 + off + 0x10) = uVar2;
    }
    else {
      *(u32 *)((int)param_1 + off + 0x10) = 0;
    }
    i = i + 1;
    off = off + 4;
  } while (i < 8);
  return param_1;
}
