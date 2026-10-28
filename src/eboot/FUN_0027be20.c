/* HSTMATCH module=EBOOT.BIN start=0x0027be20 end=0x0027be44 symbol=FUN_0027be20 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0027c75c();
extern void FUN_0027cc28();

void FUN_0027be20(void)
{
  u32 uVar1;
  
  uVar1 = FUN_0027c75c();
  FUN_0027cc28(uVar1);
}
