/* HSTMATCH module=EBOOT.BIN start=0x000511c4 end=0x00051274 symbol=FUN_000511c4 lang=c99 */
/* Clone of src/sharing_main/FUN_00051ad8_00051ad8.c (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: restored the receiver argument; matching idiom: volatile reload of the just-stored +4 field before FUN_0004ff14; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0004f52c(void *,int,int,int);
extern int FUN_0004ff14(void *,int,int);
extern int FUN_0004ff6c(void *,int,int);
extern void FUN_00051358(u32);
extern u32 DAT_00311170;

void FUN_000511c4(int param_1,u32 param_2,u32 param_3)
{
  u32 uVar1;
  
  FUN_00051358(param_1);
  uVar1 = FUN_0004f52c(&DAT_00311170,param_2,0,param_3);
  *(u32 *)(param_1 + 4) = uVar1;
  {
    int value = *(volatile int *)(param_1 + 4);
    uVar1 = FUN_0004ff14(&DAT_00311170,value,0);
  }
  *(u32 *)(param_1 + 8) = uVar1;
  uVar1 = FUN_0004ff6c(&DAT_00311170,*(u32 *)(param_1 + 4),0);
  *(u32 *)(param_1 + 0xc) = uVar1;
  *(float *)(param_1 + 0x10) = 1.0f / (float)*(int *)(param_1 + 8);
  *(float *)(param_1 + 0x14) = 1.0f / (float)*(int *)(param_1 + 0xc);
}
