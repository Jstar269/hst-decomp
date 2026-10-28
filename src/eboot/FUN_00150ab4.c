/* HSTMATCH module=EBOOT.BIN start=0x00150ab4 end=0x00150b6c symbol=FUN_00150ab4 lang=c99 */
/* Clone of src/sharing_main/FUN_0015caec.c (hstclone.py tag c164820): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the store to DAT_0034a114+0xfd comes before `uVar2 = 1;` (the order Ghidra printed was 2 words off); found with hstnearperm.py and reduced to this one change; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_0034a114;
extern int FUN_0014c384();
extern void FUN_001cc784();
extern int FUN_001cd13c();
extern int FUN_001cd284();

u32 FUN_00150ab4(int param_1,u32 *param_2)
{
  int iVar1;
  u32 uVar2;
  int uVar3;
  u32 *puVar4;
  u32 *puVar5;
  
  iVar1 = FUN_001cd13c(DAT_0034a114);
  if (iVar1 == 0) {
    uVar2 = *param_2;
    uVar3 = (unsigned char)FUN_001cd284(DAT_0034a114);
    puVar4 = (u32 *)FUN_0014c384(uVar2,*(u32 *)(*(int *)(param_1 + 4) + 0x10));
    *puVar4 = uVar3;
    FUN_001cc784(DAT_0034a114,*(u32 *)(*(int *)(param_1 + 4) + 0xc));
    iVar1 = FUN_001cd284(DAT_0034a114);
    if (iVar1 == 0) {
      puVar5 = (u32 *)FUN_0014c384(uVar2,0xb);
      *puVar5 = 0;
    }
    *(u8 *)(DAT_0034a114 + 0xfd) = 0;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
