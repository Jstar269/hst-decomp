/* HSTMATCH module=EBOOT.BIN start=0x0017d59c end=0x0017d728 symbol=FUN_0017d59c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: flag local is unsigned char (lbu) and the conditional param_2 reassignment is a ternary; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000943d0();
extern void FUN_0017c39c();
extern void FUN_0017c6d4();
extern void FUN_001fe0f4();
extern int FUN_001fe244();
extern int FUN_001fe584();
extern void FUN_001fe7b8();

void FUN_0017d59c(int param_1,int param_2,u32 param_3,int param_4,int param_5, u32 param_6)
{
  int iVar1;
  unsigned char local_1;
  
  local_1 = '\0';
  iVar1 = FUN_001fe244(param_1 + 0x5c,&local_1,param_5,param_3,param_2,param_4,param_6);
  if (iVar1 != 0x7fffffff) {
    param_2 = (local_1 != '\0') ? param_1 + iVar1 * 0x20 + 100 : param_2;
    FUN_001fe584(param_1 + 0x1a0,param_5,param_3,param_2,param_4);
    FUN_001fe7b8(param_1 + 0x1a0);
    if (param_4 == 0) {
      *(u32 *)(param_1 + 0x19c) = 0;
      *(u32 *)(param_1 + 0x2e0) = 0;
      FUN_001fe0f4(0);
      FUN_0017c6d4(param_1,1);
      FUN_0017c39c(param_1,1);
    }
    else {
      *(u32 *)(param_1 + 0x19c) = 3;
      *(u32 *)(param_1 + 0x2e0) = 3;
      if (*(int *)(param_2 + 0x14) != 0x7fffffff) {
        FUN_000943d0(*(int *)(*(int *)(param_1 + 8) + param_5 * 4) + 0x10,5);
      }
      iVar1 = *(int *)(param_2 + 0xc);
      if (iVar1 != 0x7fffffff) {
        FUN_000943d0(*(int *)(*(int *)(param_1 + 8) + param_5 * 4) + 0x10,3);
      }
      iVar1 = *(int *)(param_2 + 0x10);
      if (iVar1 != 0x7fffffff) {
        FUN_000943d0(*(int *)(*(int *)(param_1 + 8) + param_5 * 4) + 0x10,4);
      }
    }
  }
}
