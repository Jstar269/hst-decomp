/* HSTMATCH module=EBOOT.BIN start=0x00002df8 end=0x00002e7c symbol=FUN_00002df8 lang=c99 */
/* Clone of src/sharing_main/FUN_00002df8.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();
extern u32 FUN_00002c34();
extern void FUN_00002e7c();
extern u32 FUN_00002e98();

int FUN_00002df8(int param_1,short param_2)
{
  int *piVar1;
  u32 uVar2;
  u32 *puVar3;
  
  if (param_1 != 0) {
    piVar1 = (int *)FUN_00002c34();
    if (*piVar1 != 0) {
      uVar2 = FUN_00002e98(param_1);
      puVar3 = (u32 *)FUN_00002c34(param_1);
      FUN_00002e7c(uVar2,*puVar3);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
