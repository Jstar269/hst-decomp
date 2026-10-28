/* HSTMATCH module=hstp_trans_main.prx start=0x00132a58 end=0x00132ae0 symbol=FUN_00132a58 lang=c99 */
/* Clone of src/eboot/FUN_001277e8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e47e8;
extern void FUN_00058090();
extern void FUN_00094eb8();

void FUN_00132a58(int param_1)
{
  int *piVar1;
  int iVar4;
  int iVar3;
  int iVar2;
  
  FUN_00094eb8();
  iVar4 = *(int *)(param_1 + 0x58);
  if (iVar4 != 0) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      piVar1 = (int *)(DAT_003e47e8 + iVar2);
      if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
        FUN_00058090(iVar4,iVar3,piVar1,0);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < 800);
  }
}
