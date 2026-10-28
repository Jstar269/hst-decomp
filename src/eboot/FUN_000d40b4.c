/* HSTMATCH module=EBOOT.BIN start=0x000d40b4 end=0x000d4140 symbol=FUN_000d40b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r01/f0457_000d40b4_m00.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;
extern void FUN_0005f1e8();

void FUN_000d40b4(int param_1)
{
  int iVar3;
  int iVar2;
  int iVar1;
  
  iVar3 = 0;
  iVar2 = 0;
  iVar1 = param_1;
  do {
    if ((*(int *)(DAT_003386b0 + iVar2 + 0x70) != 0) &&
       (*(u8 *)(param_1 + iVar3 + 0x7a0) != '\0')) {
      FUN_0005f1e8(iVar1 + 0xe0,0);
    }
    iVar3 += 1;
    iVar2 += 4;
    iVar1 = iVar1 + 0x1b0;
  } while (iVar3 < 4);
}
