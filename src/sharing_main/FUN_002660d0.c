/* HSTMATCH module=hstp_trans_main.prx start=0x002660d0 end=0x00266118 symbol=FUN_002660d0 lang=c99 */
/* Clone of src/eboot/FUN_00255c20.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00105470();

void FUN_002660d0(int param_1,int param_2,int param_3,u32 param_4)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + param_2 * 0xa4 + param_3 * 4);
  if (iVar1 != 0) {
    FUN_00105470(iVar1,param_4);
  }
}
