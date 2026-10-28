/* HSTMATCH module=EBOOT.BIN start=0x0009044c end=0x000904dc symbol=FUN_0009044c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;
extern u32 DAT_00340284;
extern int FUN_000904dc();
extern void FUN_000b1610();

void FUN_0009044c(int param_1,u32 param_2)
{
  u32 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_003386b0 + 0x3c);
  if (((iVar2 == 4) || (iVar2 == 5)) ||
     ((iVar2 == 7 && (*(u8 *)(*(int *)(DAT_00340284 + 0x80) + 0x78) == '\0')))) {
    uVar1 = FUN_000904dc(param_1);
    FUN_000b1610(uVar1,param_2,*(u32 *)(param_1 + 0x238),*(u32 *)(param_1 + 0x23c));
  }
}
