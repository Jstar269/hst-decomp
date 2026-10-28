/* HSTMATCH module=EBOOT.BIN start=0x0013110c end=0x0013115c symbol=FUN_0013110c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0001f1fc();
extern void FUN_001240fc();
extern u32 FUN_00125218();

void FUN_0013110c(int param_1)
{
  u32 uVar1;
  
  FUN_0001f1fc(*(u32 *)(param_1 + 0x80),1);
  FUN_001240fc(*(u32 *)(param_1 + 0x80),0,0);
  uVar1 = FUN_00125218(*(u32 *)(param_1 + 0x80));
  *(u32 *)(param_1 + 0x88) = uVar1;
  *(u32 *)(param_1 + 0x8c) = 3;
}
