/* HSTMATCH module=EBOOT.BIN start=0x002261f8 end=0x0022621c symbol=FUN_002261f8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002261f8(u32 *param_1,u32 *param_2,u32 *param_3,u32 *param_4, u32 *param_5)
{
  *param_1 = *param_2;
  param_1[1] = *param_3;
  param_1[2] = *param_4;
  param_1[3] = *param_5;
}
