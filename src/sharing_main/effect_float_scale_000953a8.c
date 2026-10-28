/* HSTMATCH module=hstp_trans_main.prx start=0x000953a8 end=0x00095448 symbol=FUN_000953a8 lang=c99 */
/* Clone of src/eboot/effect_float_scale_00093484.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: local declaration order changed (uVar3, pfVar2, iVar1) to fix the saved-register assignment; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00378ad4;
extern int FUN_00055c0c(float, int);
extern void FUN_0006f80c(float param_1,float param_2,int param_3);

void FUN_000953a8(float param_1,int param_2)
{
  u32 uVar3;
  float *pfVar2;
  int iVar1;
  
  if ((*(int *)(param_2 + 0x58) != 0) &&
     (FUN_00055c0c((float)(param_1),(int)(*(int *)(param_2 + 0x58))), *(int *)(param_2 + 0x28) == 1)) {
    uVar3 = 0;
    pfVar2 = (float *)&DAT_00378ad4;
    iVar1 = 0;
    do {
      FUN_0006f80c(param_1 * *pfVar2,param_1 * *pfVar2,*(int *)(param_2 + 0x24) + iVar1);
      uVar3 = uVar3 + 1;
      pfVar2 = pfVar2 + 1;
      iVar1 = iVar1 + 8;
    } while (uVar3 < 7);
  }
}
