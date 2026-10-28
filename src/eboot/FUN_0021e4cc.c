/* HSTMATCH module=EBOOT.BIN start=0x0021e4cc end=0x0021e520 symbol=FUN_0021e4cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0082_0021e4cc_m00.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_002af920();

void FUN_0021e4cc(int param_1,u8 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  *(u8 *)(param_1 + 0x1e4) = param_2;
  *(u8 *)(param_1 + 0x208) = 1;
  if ((param_3 != 0) &&
     (iVar2 = *(int *)(param_1 + 0x200), iVar1 = FUN_002af920(*(int *)(param_1 + 0x170)),
     iVar2 >= iVar1)) {
    *(u8 *)(param_1 + 0x208) = 0;
  }
}
