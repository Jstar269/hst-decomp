/* HSTMATCH module=hstp_trans_main.prx start=0x0004a128 end=0x0004a174 symbol=FUN_0004a128 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();

u32 * FUN_0004a128(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[7] = 0;
  param_1[8] = 0xffffffff;
  FUN_000114c0(param_1 + 3,0,0x10);
  return param_1;
}
