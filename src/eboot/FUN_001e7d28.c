/* HSTMATCH module=EBOOT.BIN start=0x001e7d28 end=0x001e7d70 symbol=FUN_001e7d28 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e7d70();
extern u32 FUN_001ee200();

void FUN_001e7d28(int param_1)
{
  FUN_001e2694();
  FUN_00103628(*(u32 *)(param_1 + 0x25b8),0);
  FUN_001ee200();
  FUN_001e7d70(param_1,0,0);
}
