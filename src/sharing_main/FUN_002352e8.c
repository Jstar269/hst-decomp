/* HSTMATCH module=hstp_trans_main.prx start=0x002352e8 end=0x0023530c symbol=FUN_002352e8 lang=c99 */
/* Clone of src/eboot/FUN_00225d74.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002352e8(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x20);
  *(u32 *)(iVar1 + 0x78) = 0xffffffff;
  if (param_2 != 0) {
    *(u32 *)(iVar1 + 0x7c) = 0;
    *(u32 *)(iVar1 + 0x80) = 0;
  }
}
