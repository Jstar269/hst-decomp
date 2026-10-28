/* HSTMATCH module=EBOOT.BIN start=0x0029045c end=0x002904d4 symbol=FUN_0029045c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002ff4e4[];
extern char DAT_002ff50c[];
extern void FUN_0028fb44();
extern int FUN_002b7800();
extern int FUN_002b7808();

u32 FUN_0029045c(u32 param_1)
{
  int iVar1;
  u32 uVar2;
  
  iVar1 = FUN_002b7808(param_1,0,0,0,0);
  if (iVar1 < 0) {
    FUN_0028fb44(DAT_002ff4e4,iVar1);
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_002b7800(param_1);
    if (iVar1 < 0) {
      FUN_0028fb44(DAT_002ff50c,iVar1);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}
