/* HSTMATCH module=EBOOT.BIN start=0x001e5f50 end=0x001e5fbc symbol=FUN_001e5f50 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e6224();

void FUN_001e5f50(int param_1,u32 param_2,u32 param_3,int param_4)
{
  FUN_001e2694(param_1);
  FUN_00103628(*(int *)(param_1 + 0x1958),0);
  FUN_001e6224(param_1,param_2,param_3,param_4,'\0');
}
