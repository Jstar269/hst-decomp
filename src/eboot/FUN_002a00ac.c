/* HSTMATCH module=EBOOT.BIN start=0x002a00ac end=0x002a0140 symbol=FUN_002a00ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_002a00ac.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002cba78[];
extern char DAT_002cba8c[];
extern char DAT_002cbad0[];
extern char DAT_002cbb14[];
extern void FUN_0029e3cc();
extern int FUN_002b78d8();
extern int FUN_002b7920();

void FUN_002a00ac(int param_1,u32 param_2)
{
  u32 uVar2;
  int iVar1;
  int local_4;
  
  iVar1 = FUN_002b7920(DAT_002cbb14,param_2,0x28,0x18000,0,0);
  *(int *)(param_1 + 0x28) = iVar1;
  if (iVar1 < 0) {
    FUN_0029e3cc(DAT_002cbad0,iVar1);
  }
  local_4 = param_1;
  iVar1 = FUN_002b78d8(*(u32 *)(param_1 + 0x28),4,&local_4);
  if (iVar1 < 0) {
    FUN_0029e3cc(DAT_002cba8c,*(u32 *)(param_1 + 0x28));
    uVar2 = *(u32 *)(param_1 + 0x28);
  }
  else {
    uVar2 = *(u32 *)(param_1 + 0x28);
  }
  FUN_0029e3cc(DAT_002cba78,uVar2);
}
