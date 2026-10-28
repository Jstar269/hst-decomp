/* HSTMATCH module=hstp_trans_main.prx start=0x000955fc end=0x00095674 symbol=FUN_000955fc lang=c99 */
/* Clone of src/eboot/FUN_000936d8.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00059de4();

void FUN_000955fc(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (iVar1 != 0) {
    FUN_00059de4(iVar1,0xffffffff);
    *(u32 *)(iVar1 + 0xd0) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 0) {
    FUN_00059de4(iVar1,0xffffffff);
    *(u32 *)(iVar1 + 0xd0) = 0;
  }
  iVar1 = *(int *)(param_1 + 100);
  if (iVar1 != 0) {
    FUN_00059de4(iVar1,0xffffffff);
    *(u32 *)(iVar1 + 0xd0) = 0;
  }
}
