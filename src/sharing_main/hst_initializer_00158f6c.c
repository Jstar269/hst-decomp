/* HSTMATCH module=hstp_trans_main.prx start=0x00158f6c end=0x00159024 symbol=FUN_00158f6c lang=c99 */
/* Clone of src/eboot/hst_initializer_0014d484.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the loop counter is an unsigned local declared before the u8-offset local (counter s1, offset s0, sltiu); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b162c;
extern u8 DAT_003b16d8;
extern u32 FUN_0015b028();
extern u32 FUN_0015b03c();
extern u16 FUN_0015b050();

#pragma opt_strength_reduction off

u32 * FUN_00158f6c(u32 *param_1,u32 param_2)
{
  u32 uVar2;
  int r;
  u32 i;
  int off;
  
  *param_1 = (unsigned int)(&DAT_003b16d8);
  *(u8 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_003b162c);
  r = FUN_0015b050(param_2);
  param_1[2] = r & 0xffff;
  uVar2 = FUN_0015b03c(param_2);
  param_1[3] = uVar2;
  i = 0;
  off = 0;
  do {
    if (i < (u32)param_1[3]) {
      uVar2 = FUN_0015b028(param_2);
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
