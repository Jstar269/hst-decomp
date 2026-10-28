/* HSTMATCH module=EBOOT.BIN start=0x00192d8c end=0x00192e18 symbol=FUN_00192d8c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r02/f0247_00192d8c_m04.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();
extern void FUN_00192e18();
extern void FUN_00192f18();

int FUN_00192d8c(int param_1,short param_2)
{
  int iVar1;
  u8 auStack_4 [4];
  u32 local_8;
  int local_c;
  
  if (param_1 != 0) {
    FUN_00192e18();
    iVar1 = param_1 + 4;
    if (((iVar1 != 0) && (iVar1 != 0)) && (iVar1 != 0)) {
      local_c = param_1 + 8;
      local_8 = *(u32 *)(0xc + param_1);
      FUN_00192f18(auStack_4,iVar1,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
