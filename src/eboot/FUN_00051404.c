/* HSTMATCH module=EBOOT.BIN start=0x00051404 end=0x00051450 symbol=FUN_00051404 lang=c99 */
/* Clone of src/sharing_main/FUN_00051da4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00311170;
extern u32 FUN_00050210();

void FUN_00051404(int param_1,u8 param_2,u8 param_3)
{
  int iVar1;
  
  iVar1 = FUN_00050210((int)&DAT_00311170,*(u32 *)(param_1 + 4));
  if (iVar1 != 0) {
    *(u8 *)(iVar1 + 0x92) = param_2;
    *(u8 *)(iVar1 + 0x93) = param_3;
  }
}
