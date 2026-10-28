/* HSTMATCH module=EBOOT.BIN start=0x00093484 end=0x00093524 symbol=FUN_00093484 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: local declaration order changed (uVar3, pfVar2, iVar1) to fix the saved-register assignment; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d28b8;
extern int FUN_000550ec(float, int);
extern void FUN_0006e110(float param_1,float param_2,int param_3);

void FUN_00093484(float param_1,int param_2)
{
  u32 uVar3;
  float *pfVar2;
  int iVar1;
  
  if ((*(int *)(param_2 + 0x58) != 0) &&
     (FUN_000550ec((float)(param_1),(int)(*(int *)(param_2 + 0x58))), *(int *)(param_2 + 0x28) == 1)) {
    uVar3 = 0;
    pfVar2 = (float *)&DAT_002d28b8;
    iVar1 = 0;
    do {
      FUN_0006e110(param_1 * *pfVar2,param_1 * *pfVar2,*(int *)(param_2 + 0x24) + iVar1);
      uVar3 = uVar3 + 1;
      pfVar2 = pfVar2 + 1;
      iVar1 = iVar1 + 8;
    } while (uVar3 < 7);
  }
}
