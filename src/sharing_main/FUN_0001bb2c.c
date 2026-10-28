/* HSTMATCH module=hstp_trans_main.prx start=0x0001bb2c end=0x0001bb38 symbol=FUN_0001bb2c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0001bb2c(int param_1,u32 param_2,u32 param_3)
{
  *(u32 *)(param_1 + 0x18) = param_2;
  *(u32 *)(param_1 + 0x1c) = param_3;
}
