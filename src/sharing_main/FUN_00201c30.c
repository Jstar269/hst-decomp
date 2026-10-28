/* HSTMATCH module=hstp_trans_main.prx start=0x00201c30 end=0x00201ca4 symbol=FUN_00201c30 lang=c99 */
/* Clone of src/eboot/FUN_001f3770.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001f08bc();
extern u32 FUN_002015d8();
extern void FUN_00207b70();
extern void FUN_0020a040();

void FUN_00201c30(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_002015d8(param_1,*(u32 *)(param_1 + 0x40),0);
  if (iVar1 == 0x14) {
    FUN_00207b70(param_1);
  }
  else {
    if (iVar1 == 0xb) {
      FUN_001f08bc(*(u32 *)(param_1 + 0x510));
    }
    FUN_0020a040(param_1 + 0x3c,iVar1,1);
  }
}
