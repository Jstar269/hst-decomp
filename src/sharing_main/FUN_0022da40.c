/* HSTMATCH module=hstp_trans_main.prx start=0x0022da40 end=0x0022da94 symbol=FUN_0022da40 lang=c99 */
/* Clone of src/eboot/FUN_0021e4cc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_002bf370();

void FUN_0022da40(int param_1,u8 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  *(u8 *)(param_1 + 0x1e4) = param_2;
  *(u8 *)(param_1 + 0x208) = 1;
  if ((param_3 != 0) &&
     (iVar2 = *(int *)(param_1 + 0x200), iVar1 = FUN_002bf370(*(int *)(param_1 + 0x170)),
     iVar2 >= iVar1)) {
    *(u8 *)(param_1 + 0x208) = 0;
  }
}
