/* HSTMATCH module=hstp_trans_main.prx start=0x0006cfb0 end=0x0006cfd0 symbol=FUN_0006cfb0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0006cfb0(u32 *param_1,u8 *param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(u8 *)(param_1 + 2) = *param_2;
  param_1[3] = (unsigned int)(param_1 + 1);
  return param_1;
}
