/* HSTMATCH module=EBOOT.BIN start=0x00279b50 end=0x00279b7c symbol=FUN_00279b50 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00279b50(char *param_1)
{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x45c)) &&
     (iVar1 = *(int *)(param_1 + 0x45c) + -1, *(int *)(param_1 + 0x45c) = iVar1, iVar1 < 1)) {
    *(u32 *)(param_1 + 0x45c) = 0;
    *(u8 *)(param_1 + 0x454) = 1;
  }
}
