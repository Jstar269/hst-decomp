/* HSTMATCH module=hstp_trans_main.prx start=0x00045830 end=0x0004587c symbol=FUN_00045830 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000459d0();
extern void FUN_00045af8();

u32 * FUN_00045830(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  FUN_00045af8(param_1 + 3);
  FUN_000459d0(param_1);
  return param_1;
}
