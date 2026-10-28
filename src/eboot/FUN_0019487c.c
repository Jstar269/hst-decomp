/* HSTMATCH module=EBOOT.BIN start=0x0019487c end=0x0019494c symbol=FUN_0019487c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0460_0019487c_m01.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0005743c();
extern void FUN_00194438();

void FUN_0019487c(int param_1,int param_2,int param_3,int param_4,u32 param_5,int param_6)
{
  bool bVar1;
  int iVar3;
  int iVar2;
  u8 local_1;
  
  local_1 = '\0';
  FUN_00194438(&local_1,param_1,param_2,param_5,param_6);
  if (local_1 != '\0') {
    bVar1 = false;
    if (param_6 != 0) {
      bVar1 = *(u8 *)(param_2 + 0x7c) == '\x02';
    }
    if (((param_3 != 0) && (iVar3 = *(int *)(param_1 + 0x58), iVar3 != 0)) &&
       (iVar2 = 0, 0 < param_4)) {
      do {
        FUN_0005743c(iVar3,iVar2,param_3,bVar1);
        iVar2 = iVar2 + 1;
        param_3 = param_3 + 0x10;
      } while (iVar2 < param_4);
    }
  }
}
