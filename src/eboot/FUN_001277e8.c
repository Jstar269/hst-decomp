/* HSTMATCH module=EBOOT.BIN start=0x001277e8 end=0x00127870 symbol=FUN_001277e8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0385_001277e8_m14.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0033b4a8;
extern void FUN_0005743c();
extern void FUN_00093024();

void FUN_001277e8(int param_1)
{
  int *piVar1;
  int iVar4;
  int iVar3;
  int iVar2;
  
  FUN_00093024();
  iVar4 = *(int *)(param_1 + 0x58);
  if (iVar4 != 0) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      piVar1 = (int *)(DAT_0033b4a8 + iVar2);
      if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
        FUN_0005743c(iVar4,iVar3,piVar1,0);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < 800);
  }
}
