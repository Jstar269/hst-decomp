/* HSTMATCH module=EBOOT.BIN start=0x00190ed0 end=0x00190f00 symbol=FUN_00190ed0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00190ed0(u32 *param_1,u32 *param_2,u32 param_3,u32 param_4)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_3;
  param_1[5] = param_4;
  return param_1;
}
