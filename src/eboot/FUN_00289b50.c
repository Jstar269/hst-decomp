/* HSTMATCH module=EBOOT.BIN start=0x00289b50 end=0x00289b68 symbol=FUN_00289b50 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00289b50(u32 *param_1,u32 *param_2)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  return param_1;
}
