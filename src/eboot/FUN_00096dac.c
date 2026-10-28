/* HSTMATCH module=EBOOT.BIN start=0x00096dac end=0x00096e18 symbol=FUN_00096dac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0402_00096dac_m05.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;
extern void FUN_00097110();

void FUN_00096dac(void)
{
  int iVar1;
  int iVar3;
  int iVar2;
  
  if (DAT_003386b0 != 0) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      iVar1 = *(int *)(DAT_003386b0 + iVar2 + 0x70);
      if (iVar1 != 0) {
        FUN_00097110(iVar1);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < 4);
  }
}
