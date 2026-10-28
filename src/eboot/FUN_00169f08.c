/* HSTMATCH module=EBOOT.BIN start=0x00169f08 end=0x00169f24 symbol=FUN_00169f08 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0000c6dc(float param_1,float param_2);

void FUN_00169f08(float *param_1,float *param_2)
{
  FUN_0000c6dc(*param_2 - *param_1,param_2[2] - param_1[2]);
}
