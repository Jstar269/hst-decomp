/* HSTMATCH module=EBOOT.BIN start=0x00233fc4 end=0x0023404c symbol=FUN_00233fc4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * DAT_0034a664;
extern u8 DAT_0034a678;
extern void FUN_00233518();
extern void FUN_00234158();
extern void FUN_0023466c();

void FUN_00233fc4(u32 param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8)
{
  bool bVar1;
  int iVar2;
  
  if (DAT_0034a664 != (int *)0x0) {
    FUN_00233518(DAT_0034a664,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    iVar2 = DAT_0034a664[3];
    bVar1 = true;
    if ((iVar2 != 6) && (iVar2 != 7)) {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_00234158((int *)&DAT_0034a678,2);
    }
    else if (iVar2 == 9) {
      FUN_0023466c((int *)&DAT_0034a678);
    }
  }
}
