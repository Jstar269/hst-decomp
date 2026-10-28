/* HSTMATCH module=EBOOT.BIN start=0x0011ecdc end=0x0011ed04 symbol=FUN_0011ecdc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0011ecdc(u32 *param_1,u32 *param_2)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return param_1;
}
