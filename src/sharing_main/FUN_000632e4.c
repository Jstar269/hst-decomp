/* HSTMATCH module=hstp_trans_main.prx start=0x000632e4 end=0x00063304 symbol=FUN_000632e4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_000632e4(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0xffffffff;
  *(u8 *)(param_1 + 2) = 0;
  param_1[3] = 0xffffffff;
  param_1[4] = 0;
  return param_1;
}
