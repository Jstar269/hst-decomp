/* HSTMATCH module=EBOOT.BIN start=0x0001f394 end=0x0001f3ec symbol=FUN_0001f394 lang=c99 */
/* Clone of src/sharing_main/FUN_0001f1cc.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0001f3ec();

void FUN_0001f394(u32 param_1,u32 param_2)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_0001f3ec(param_1,param_2,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
}
