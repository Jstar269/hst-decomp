/* HSTMATCH module=hstp_trans_main.prx start=0x001b179c end=0x001b17f0 symbol=FUN_001b179c lang=c99 */
/* Clone of src/eboot/FUN_001a41d0.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted dispatch condition; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00177b5c();

void FUN_001b179c(int param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_00177b5c(**(u32 **)(*(int *)(param_1 + 0x378) + *(int *)(param_1 + 0x2c4) * 4));
  }
  else {
    *(u32 *)(param_1 + 0x2c0) = *(u32 *)(param_1 + 0x2cc);
    *(u32 *)(param_1 + 0x2c4) = *(u32 *)(param_1 + 0x2d0);
    *(u32 *)(param_1 + 0x2c8) = *(u32 *)(param_1 + 0x2d4);
  }
}
