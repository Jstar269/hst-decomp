/* HSTMATCH module=hstp_trans_main.prx start=0x00054098 end=0x000540d8 symbol=FUN_00054098 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00054260();

int FUN_00054098(int param_1)
{
  *(u32 *)(param_1 + 0x18) = 0;
  *(u32 *)(param_1 + 0x1c) = 0;
  *(u32 *)(param_1 + 0x20) = 0;
  *(u32 *)(param_1 + 0x24) = 0;
  *(u32 *)(param_1 + 0x28) = 0;
  *(u32 *)(param_1 + 0x2c) = 0;
  FUN_00054260();
  return param_1;
}
