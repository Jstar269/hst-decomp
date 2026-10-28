/* HSTMATCH module=EBOOT.BIN start=0x0029dfdc end=0x0029e024 symbol=FUN_0029dfdc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415ac;
extern void FUN_000fe43c();
extern void FUN_00295cdc();
extern void FUN_0029ade8();
extern int FUN_0029e024();

void FUN_0029dfdc(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  FUN_0029e024();
  FUN_000fe43c(0);
  *(u32 *)(iVar1 + 0x28) = 0;
  FUN_0029ade8(iVar1,3);
  FUN_00295cdc(DAT_003415ac);
}
