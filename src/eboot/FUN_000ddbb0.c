/* HSTMATCH module=EBOOT.BIN start=0x000ddbb0 end=0x000ddc6c symbol=FUN_000ddbb0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;
extern int FUN_0008882c();

void FUN_000ddbb0(u32 param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = FUN_0008882c(DAT_003386b0);
  if (param_3 == *(int *)(iVar1 + 0x144)) {
    *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 500) =
         *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 500) + 1;
    iVar1 = FUN_0008882c(DAT_003386b0);
    if (param_2 == *(int *)(iVar1 + 0x144)) {
      *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1f0) =
           *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1f0) + 1;
    }
  }
  else {
    iVar1 = FUN_0008882c(DAT_003386b0);
    if (param_2 == *(int *)(iVar1 + 0x144)) {
      *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1f8) =
           *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1f8) + 1;
    }
  }
}
