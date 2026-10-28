/* HSTMATCH module=hstp_trans_main.prx start=0x00023bc4 end=0x00023be0 symbol=FUN_00023bc4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00023bc4(int param_1,u32 param_2,u32 param_3,u32 param_4)
{
  if (param_1 != 0) {
    *(u32 *)(param_1 + 0x6c) = param_4;
    *(u32 *)(param_1 + 100) = param_2;
    *(u32 *)(param_1 + 0x68) = param_3;
  }
}
