/* HSTMATCH module=EBOOT.BIN start=0x0019d1b8 end=0x0019d1f4 symbol=FUN_0019d1b8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0019b490();

void FUN_0019d1b8(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8)
{
  if (*(int *)(param_1 + 0x90) != 0) {
    FUN_0019b490(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
  }
}
