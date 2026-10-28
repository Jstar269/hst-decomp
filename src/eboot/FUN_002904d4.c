/* HSTMATCH module=EBOOT.BIN start=0x002904d4 end=0x002905bc symbol=FUN_002904d4 lang=c99 data=0x002ff550 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256b); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ff550-0x002ff56a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern char DAT_002ff534[];
extern char DAT_002ff56c[];
extern u32 * FUN_000149a8();
extern u8 * FUN_00022d7c();
extern void FUN_0028fb44();
extern int FUN_002b7988();

u32 FUN_002904d4(int param_1,u32 param_2,u32 param_3)
{
  u32 uVar1;
  int iVar2;
  int local_4;
  
  if (*(u8 *)(param_1 + 0x28) == '\0') {
    FUN_0028fb44(DAT_002ff534);
    uVar1 = 0;
  }
  else {
    *(u32 *)(param_1 + 0x8c) = 1;
    FUN_000149a8(param_1 + 0x94);
    *(u32 *)(param_1 + 0x90) = param_3;
    FUN_00022d7c(*(u32 *)(param_1 + 0x2c),0,0x88000);
    iVar2 = FUN_002b7988(*(u32 *)(param_1 + 0x88),param_1 + 0x8c,0x48,0,&local_4);
    if (iVar2 == -0x7ffdfe4d) {
      FUN_0028fb44("Play(): request is full.\n");
    }
    else if ((iVar2 != 0) || (local_4 != 0x48)) {
      FUN_0028fb44(DAT_002ff56c,iVar2,local_4);
      return 0;
    }
    uVar1 = 1;
    *(u8 *)(param_1 + 0x29) = 1;
  }
  return uVar1;
}
