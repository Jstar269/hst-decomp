/* HSTMATCH module=hstp_trans_main.prx start=0x0015caec end=0x0015cba4 symbol=FUN_0015caec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the store to DAT_003f344c+0xfd comes before `uVar2 = 1;` (the order Ghidra printed was 2 words off); found with hstnearperm.py and reduced to this one change; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003f344c;
extern int FUN_00157e10();
extern void FUN_001daeb8();
extern int FUN_001db8a4();
extern int FUN_001db960();

u32 FUN_0015caec(int param_1,u32 *param_2)
{
  int iVar1;
  u32 uVar2;
  int uVar3;
  u32 *puVar4;
  u32 *puVar5;
  
  iVar1 = FUN_001db8a4(DAT_003f344c);
  if (iVar1 == 0) {
    uVar2 = *param_2;
    uVar3 = (unsigned char)FUN_001db960(DAT_003f344c);
    puVar4 = (u32 *)FUN_00157e10(uVar2,*(u32 *)(*(int *)(param_1 + 4) + 0x10));
    *puVar4 = uVar3;
    FUN_001daeb8(DAT_003f344c,*(u32 *)(*(int *)(param_1 + 4) + 0xc));
    iVar1 = FUN_001db960(DAT_003f344c);
    if (iVar1 == 0) {
      puVar5 = (u32 *)FUN_00157e10(uVar2,0xb);
      *puVar5 = 0;
    }
    *(u8 *)(DAT_003f344c + 0xfd) = 0;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
