/* HSTMATCH module=EBOOT.BIN start=0x00117c24 end=0x00117c74 symbol=FUN_00117c24 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00340284;
extern void FUN_00117d70();
extern void FUN_00117dd0();

void FUN_00117c24(int param_1)
{
  FUN_00117d70(param_1,1,0xffffffec,1);
  FUN_00117dd0(param_1);
  *(u8 *)(param_1 + 0x4c) = 1;
  *(u8 *)(*(int *)(DAT_00340284 + 0x80) + 0x79) = 0;
}
