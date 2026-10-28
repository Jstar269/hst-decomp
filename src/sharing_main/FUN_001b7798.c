/* HSTMATCH module=hstp_trans_main.prx start=0x001b7798 end=0x001b77d4 symbol=FUN_001b7798 lang=c99 */
/* Clone of src/eboot/FUN_001aa1cc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00177234();
extern u32 FUN_001aa91c();

void FUN_001b7798(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001aa91c();
  iVar1 = FUN_00177234(*(u32 *)(iVar1 + 0x2e4));
  *(int *)(*(int *)(param_1 + 0x98) + 0x24) = *(int *)(*(int *)(param_1 + 0x98) + 0x28) + iVar1;
}
