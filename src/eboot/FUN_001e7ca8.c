/* HSTMATCH module=EBOOT.BIN start=0x001e7ca8 end=0x001e7cf0 symbol=FUN_001e7ca8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();
extern void FUN_002178ac();

void FUN_001e7ca8(int param_1)
{
  FUN_00103628(*(u32 *)(param_1 + 0x250c),0);
  FUN_002178ac(param_1 + 0x252c,0,0x80,10);
  *(u32 *)(param_1 + 0x2528) = 0x46;
}
