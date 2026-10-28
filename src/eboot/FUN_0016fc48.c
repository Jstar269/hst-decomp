/* HSTMATCH module=EBOOT.BIN start=0x0016fc48 end=0x0016fca4 symbol=FUN_0016fc48 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0404_0016fc48_m02.c); exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

void FUN_0016fc48(int param_1)
{
  int iVar1;
  int iVar3;
  int iVar2;
  
  iVar3 = 0;
  iVar2 = param_1;
  do {
    iVar1 = (**(code **)(param_1 + 1000))(iVar3);
    iVar3 = iVar3 + 1;
    *(char *)(iVar1 + 1) = (char)*(u32 *)(iVar2 + 0xc0);
    iVar2 = iVar2 + 4;
  } while (iVar3 < 0xf);
}
