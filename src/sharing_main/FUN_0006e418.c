/* HSTMATCH module=hstp_trans_main.prx start=0x0006e418 end=0x0006e458 symbol=FUN_0006e418 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0006cce0();

u32 * FUN_0006e418(u32 *param_1,int param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(u8 *)(param_1 + 2) = *(u8 *)(param_2 + 8);
  param_1[3] = (unsigned int)(param_1 + 1);
  FUN_0006cce0();
  return param_1;
}
