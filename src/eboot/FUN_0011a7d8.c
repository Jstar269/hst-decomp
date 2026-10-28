/* HSTMATCH module=EBOOT.BIN start=0x0011a7d8 end=0x0011a820 symbol=FUN_0011a7d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338b44;

u32 FUN_0011a7d8(int param_1)
{
  int iVar1;
  
  if (*(int *)(DAT_00338b44 + 0x8c) == 0) {
    iVar1 = 0;
    do {
      if (*(int *)(param_1 + 0x314) == 5) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 4;
    } while (iVar1 < 2);
  }
  return 0;
}
