/* HSTMATCH module=EBOOT.BIN start=0x001233bc end=0x001233e0 symbol=FUN_001233bc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00125218();
extern void FUN_00126304();

void FUN_001233bc(void)
{
  u32 uVar1;
  
  uVar1 = FUN_00125218();
  FUN_00126304(uVar1);
}
