/* HSTMATCH module=hstp_trans_main.prx start=0x0008e9e8 end=0x0008ea40 symbol=FUN_0008e9e8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();

u8 * FUN_0008e9e8(u8 *param_1)
{
  FUN_000114c0(param_1,0,0x14);
  *param_1 = 0;
  param_1[1] = 1;
  param_1[2] = 2;
  param_1[3] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[6] = 1;
  param_1[0x10] = 0;
  return param_1;
}
