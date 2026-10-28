/* HSTMATCH module=EBOOT.BIN start=0x0019d23c end=0x0019d268 symbol=FUN_0019d23c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_001d9eb0();

void FUN_0019d23c(int param_1)
{
  u32 uVar1;
  
  uVar1 = FUN_001d9eb0(1);
  *(u32 *)(param_1 + 0x40) = uVar1;
}
