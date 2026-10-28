/* HSTMATCH module=hstp_trans_main.prx start=0x002661a8 end=0x002661e4 symbol=FUN_002661a8 lang=c99 */
/* Clone of src/eboot/FUN_00255cf8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002661a8(int param_1,int param_2,int param_3,u32 param_4)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + param_2 * 0xa4 + param_3 * 4);
  if (iVar1 != 0) {
    *(u32 *)(iVar1 + 0x24) = param_4;
    *(u32 *)(iVar1 + 0x28) = param_4;
  }
}
