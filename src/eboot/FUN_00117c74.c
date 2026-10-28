/* HSTMATCH module=EBOOT.BIN start=0x00117c74 end=0x00117cc4 symbol=FUN_00117c74 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00340284;
extern void FUN_00117d70();
extern void FUN_00117dd0();

void FUN_00117c74(int param_1)
{
  FUN_00117d70(param_1,8,0,0);
  FUN_00117dd0(param_1);
  *(u8 *)(param_1 + 0x4c) = 0;
  *(u8 *)(*(int *)(DAT_00340284 + 0x80) + 0x79) = 1;
}
