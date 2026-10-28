/* HSTMATCH module=EBOOT.BIN start=0x00279a2c end=0x00279b24 symbol=FUN_00279a2c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002fe240[];
extern char DAT_002fe274[];
extern char DAT_002fe280[];
extern void FUN_000ffb3c();
extern int FUN_001026b8();
extern int FUN_001039d8();

void FUN_00279a2c(int param_1)
{
  u32 uVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x474) + 0xdc) < 4) {
    uVar1 = FUN_001039d8(param_1 + 0x3c,DAT_002fe240,0);
    uVar1 = FUN_001026b8(uVar1,DAT_002fe274);
    FUN_000ffb3c(uVar1,1);
    uVar1 = FUN_001039d8(param_1 + 0x3c,DAT_002fe240,0);
    uVar1 = FUN_001026b8(uVar1,DAT_002fe280);
    FUN_000ffb3c(uVar1,0);
  }
  else {
    uVar1 = FUN_001039d8(param_1 + 0x3c,DAT_002fe240,0);
    uVar1 = FUN_001026b8(uVar1,DAT_002fe274);
    FUN_000ffb3c(uVar1,0);
    uVar1 = FUN_001039d8(param_1 + 0x3c,DAT_002fe240,0);
    uVar1 = FUN_001026b8(uVar1,DAT_002fe280);
    FUN_000ffb3c(uVar1,1);
  }
}
