/* HSTMATCH module=hstp_trans_main.prx start=0x001c1138 end=0x001c1198 symbol=FUN_001c1138 lang=c99 */
/* Clone of src/eboot/FUN_001b3008.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00063304();

void FUN_001c1138(int *param_1)
{
  int iVar1;
  u32 iVar2;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0x2b4);
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 0x10);
  }
  else {
    if (iVar1 != 0) {
      FUN_00063304(iVar1,1);
      *(u32 *)(iVar2 + 0x2b4) = 0;
    }
  }
  if (((*(int *)(iVar2 + 0x10)) != 0) && ((*(int *)(iVar2 + 0x10)) != 0)) {
    FUN_00063304((*(int *)(iVar2 + 0x10)),1);
    *(u32 *)(iVar2 + 0x10) = 0;
  }
}
