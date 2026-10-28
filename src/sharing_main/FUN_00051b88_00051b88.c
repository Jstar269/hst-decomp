/* HSTMATCH module=hstp_trans_main.prx start=0x00051b88 end=0x00051c58 symbol=FUN_00051b88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: restored the receiver argument; matching idiom: volatile reload of the just-stored +4 field before FUN_000507f0; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0004fe78(void *,int,int,int,int,int);
extern int FUN_000507f0(void *,int,int);
extern int FUN_00050848(void *,int,int);
extern void FUN_00051c6c(u32);
extern u32 DAT_003ba4b0;

void FUN_00051b88(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5)
{
  u32 uVar1;
  
  FUN_00051c6c(param_1);
  uVar1 = FUN_0004fe78(&DAT_003ba4b0,param_2,param_3,0,param_4,param_5);
  *(u32 *)(param_1 + 4) = uVar1;
  {
    int value = *(volatile int *)(param_1 + 4);
    uVar1 = FUN_000507f0(&DAT_003ba4b0,value,0);
  }
  *(u32 *)(param_1 + 8) = uVar1;
  uVar1 = FUN_00050848(&DAT_003ba4b0,*(u32 *)(param_1 + 4),0);
  *(u32 *)(param_1 + 0xc) = uVar1;
  *(float *)(param_1 + 0x10) = 1.0f / (float)*(int *)(param_1 + 8);
  *(float *)(param_1 + 0x14) = 1.0f / (float)*(int *)(param_1 + 0xc);
}
