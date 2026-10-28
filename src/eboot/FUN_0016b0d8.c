/* HSTMATCH module=EBOOT.BIN start=0x0016b0d8 end=0x0016b110 symbol=FUN_0016b0d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c1e34;

int FUN_0016b0d8(int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(&DAT_002c1e34);
  do {
    if (param_1 == *piVar2) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 3);
  return 0;
}
