/* HSTMATCH module=EBOOT.BIN start=0x0016b088 end=0x0016b0c0 symbol=FUN_0016b088 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c1e28;

int FUN_0016b088(int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(&DAT_002c1e28);
  do {
    if (param_1 == *piVar2) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 3);
  return 0;
}
