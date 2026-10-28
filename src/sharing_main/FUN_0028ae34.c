/* HSTMATCH module=hstp_trans_main.prx start=0x0028ae34 end=0x0028ae60 symbol=FUN_0028ae34 lang=c99 */
/* Clone of src/eboot/FUN_00279b50.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0028ae34(char *param_1)
{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x45c)) &&
     (iVar1 = *(int *)(param_1 + 0x45c) + -1, *(int *)(param_1 + 0x45c) = iVar1, iVar1 < 1)) {
    *(u32 *)(param_1 + 0x45c) = 0;
    *(u8 *)(param_1 + 0x454) = 1;
  }
}
