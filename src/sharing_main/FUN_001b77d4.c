/* HSTMATCH module=hstp_trans_main.prx start=0x001b77d4 end=0x001b7810 symbol=FUN_001b77d4 lang=c99 */
/* Clone of src/eboot/FUN_001aa208.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00177284();
extern u32 FUN_001aa91c();

void FUN_001b77d4(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001aa91c();
  iVar1 = FUN_00177284(*(u32 *)(iVar1 + 0x2ec));
  *(int *)(*(int *)(param_1 + 0xac) + 0x24) = *(int *)(*(int *)(param_1 + 0xac) + 0x28) + iVar1;
}
