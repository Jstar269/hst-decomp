/* HSTMATCH module=hstp_trans_main.prx start=0x001c0f48 end=0x001c0fa8 symbol=FUN_001c0f48 lang=c99 */
/* Clone of src/eboot/FUN_001b2e18.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00063304();

void FUN_001c0f48(int *param_1)
{
  int iVar2;
  int iVar1;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0x2b0);
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 0x2b4);
  }
  else {
    if (iVar1 != 0) {
      FUN_00063304(iVar1,1);
      *(u32 *)(iVar2 + 0x2b0) = 0;
    }
  }
  if (((*(int *)(iVar2 + 0x2b4)) != 0) && ((*(int *)(iVar2 + 0x2b4)) != 0)) {
    FUN_00063304((*(int *)(iVar2 + 0x2b4)),1);
    *(u32 *)(iVar2 + 0x2b4) = 0;
  }
}
