/* HSTMATCH module=hstp_trans_main.prx start=0x00051e18 end=0x00051e30 symbol=FUN_00051e18 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00051e18(int param_1,u32 param_2)
{
  **(u32 **)(param_1 + 0x28) = param_2;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 4;
}
