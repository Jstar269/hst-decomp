/* HSTMATCH module=EBOOT.BIN start=0x000936d8 end=0x00093750 symbol=FUN_000936d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00059100();

void FUN_000936d8(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (iVar1 != 0) {
    FUN_00059100(iVar1,0xffffffff);
    *(u32 *)(iVar1 + 0xd0) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 0) {
    FUN_00059100(iVar1,0xffffffff);
    *(u32 *)(iVar1 + 0xd0) = 0;
  }
  iVar1 = *(int *)(param_1 + 100);
  if (iVar1 != 0) {
    FUN_00059100(iVar1,0xffffffff);
    *(u32 *)(iVar1 + 0xd0) = 0;
  }
}
