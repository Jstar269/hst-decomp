/* HSTMATCH module=EBOOT.BIN start=0x0016fca4 end=0x0016fd08 symbol=FUN_0016fca4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0405_0016fca4_m04.c); exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

void FUN_0016fca4(int param_1)
{
  u32 iVar1;
  int iVar3;
  int iVar2;
  
  if (*(u8 *)(param_1 + 0x46) != '\0') {
    iVar3 = 0;
    iVar2 = param_1;
    do {
      iVar1 = (**(code **)(param_1 + 1000))(iVar3);
      iVar3 = iVar3 + 1;
      *(short *)(iVar1 + 2) = (short)*(u32 *)(iVar2 + 0xfc);
      iVar2 = iVar2 + 4;
    } while (iVar3 < 0xf);
  }
}
