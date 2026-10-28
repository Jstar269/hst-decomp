/* HSTMATCH module=hstp_trans_main.prx start=0x0005c658 end=0x0005c688 symbol=FUN_0005c658 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0005c700();

int FUN_0005c658(int param_1)
{
  *(u32 *)(param_1 + 0x1c) = 0;
  *(u32 *)(param_1 + 0x24) = 0;
  FUN_0005c700();
  return param_1;
}
