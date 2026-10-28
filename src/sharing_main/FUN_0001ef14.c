/* HSTMATCH module=hstp_trans_main.prx start=0x0001ef14 end=0x0001ef24 symbol=FUN_0001ef14 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0001ef14(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x24) = param_2;
  *(u8 *)(param_1 + 0x2c) = param_2;
  *(u8 *)(param_1 + 0x34) = param_2;
}
