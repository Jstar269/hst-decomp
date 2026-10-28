/* HSTMATCH module=EBOOT.BIN start=0x001e54dc end=0x001e5524 symbol=FUN_001e54dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the first call's receiver argument and the member load at +0x175c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e5524();

void FUN_001e54dc(int param_1,u32 param_2)
{
  FUN_001e2694(param_1);
  FUN_00103628(*(int *)(param_1 + 0x175c),0);
  FUN_001e5524(param_1,param_2);
}
