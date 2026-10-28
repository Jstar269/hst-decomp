/* HSTMATCH module=EBOOT.BIN start=0x00266760 end=0x002667b8 symbol=FUN_00266760 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0012c364();
extern u32 FUN_0012c5ac();
extern void FUN_002667fc();

void FUN_00266760(int param_1)
{
  u8 cVar1;
  u8 uVar2;
  
  cVar1 = FUN_0012c364(param_1 + 0x80);
  if (cVar1 != '\0') {
    uVar2 = FUN_0012c5ac(param_1 + 0x80);
    *(u8 *)(param_1 + 0x120) = uVar2;
    if (*(u8 *)(param_1 + 0x120) == '\0') {
      FUN_002667fc(param_1,1);
    }
  }
}
