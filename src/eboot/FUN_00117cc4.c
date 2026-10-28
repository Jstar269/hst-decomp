/* HSTMATCH module=EBOOT.BIN start=0x00117cc4 end=0x00117d38 symbol=FUN_00117cc4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;
extern void FUN_0001f558();
extern void FUN_00117d70();
extern void FUN_00117dd0();

void FUN_00117cc4(int param_1)
{
  FUN_00117d70(param_1,((*(int *)(param_1 + 0x5c) + 10) - (*(int *)(param_1 + 0x68) + 1) % 9) % 9,
               0xffffffff,0);
  FUN_00117dd0(param_1);
  FUN_0001f558(DAT_003386b0,0x16,0,0);
}
