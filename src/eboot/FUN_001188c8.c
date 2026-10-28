/* HSTMATCH module=EBOOT.BIN start=0x001188c8 end=0x00118908 symbol=FUN_001188c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0005ba00();

void FUN_001188c8(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xec);
  if ((iVar1 != 0) && (iVar1 != 0)) {
    FUN_0005ba00(iVar1,1);
    *(u32 *)(param_1 + 0xec) = 0;
  }
}
