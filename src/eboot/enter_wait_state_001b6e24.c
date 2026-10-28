/* HSTMATCH module=EBOOT.BIN start=0x001b6e24 end=0x001b6f68 symbol=FUN_001b6e24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a/v4) corrected by hand: corrected helper return and float argument types and used the named data symbol; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338b44;
extern int DAT_0034179c;
extern int FUN_000def58(int param_1);
extern int FUN_001b2af0(int *param_1,int param_2);
extern void FUN_001b3ea4(int *param_1,float param_2);
extern void FUN_001b413c(int *param_1,float param_2,float param_3);
extern void FUN_001b4240(int *param_1,float param_2);
extern void FUN_001b464c(int *param_1,float param_2);
extern void FUN_001b871c();
extern void FUN_001b87e8(int param_1,int param_2,int param_3);
extern void FUN_001b8b48(int param_1,u32 param_2,int param_3);

void FUN_001b6e24(int param_1)
{
  int iVar1;
  u32 uVar2;
  
  FUN_001b871c();
  iVar1 = FUN_000def58((int)(DAT_00338b44));
  if (iVar1 == 0) {
    if (*(u32 *)(DAT_00338b44 + 0xa4) < 2) {
      FUN_001b87e8((int)(param_1),(int)(0),(int)(0));
      FUN_001b413c(&DAT_0034179c,0.0f,0.5f);
      uVar2 = FUN_001b2af0(&DAT_0034179c,(int)(2));
      *(u32 *)(param_1 + 0x54) = uVar2;
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    }
    else if (*(u32 *)(DAT_00338b44 + 0xa0) < 2) {
      FUN_001b87e8((int)(param_1),(int)(0),(int)(0));
      FUN_001b413c(&DAT_0034179c,0.0f,0.5f);
      uVar2 = FUN_001b2af0(&DAT_0034179c,(int)(1));
      *(u32 *)(param_1 + 0x54) = uVar2;
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    }
  }
  else {
    *(u8 *)(param_1 + 0x78) = 1;
    FUN_001b3ea4(&DAT_0034179c,0.5f);
    FUN_001b4240(&DAT_0034179c,0.5f);
    FUN_001b464c(&DAT_0034179c,0.5f);
    FUN_001b8b48((int)(param_1),(u32)(0x9a),(int)(0x18));
  }
}
