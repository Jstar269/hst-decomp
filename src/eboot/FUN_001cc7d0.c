/* HSTMATCH module=EBOOT.BIN start=0x001cc7d0 end=0x001cc830 symbol=FUN_001cc7d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000149a8();
extern int FUN_00014a40();
extern void FUN_0018aa04();

void FUN_001cc7d0(int param_1,u32 param_2)
{
  u32 uVar1;
  int iVar2;
  
  uVar1 = FUN_00014a40(param_2);
  if (uVar1 < 0x10) {
    FUN_000149a8(param_1 + 0x114,param_2);
    iVar2 = *(int *)(param_1 + 0x15c);
    FUN_0018aa04(*(u32 *)(iVar2 + 0x20));
    *(u8 *)(iVar2 + 100) = 1;
  }
}
