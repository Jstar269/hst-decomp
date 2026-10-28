/* HSTMATCH module=EBOOT.BIN start=0x001e73d8 end=0x001e744c symbol=FUN_001e73d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the mixed integer and float helper parameters and passed the pointer and float values in declared order; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002ec180[];
extern u32 FUN_00065740();
extern int FUN_001ee224();
extern void FUN_0021780c(int,int,float,float);
extern void FUN_00217834();

void FUN_001e73d8(int param_1)
{
  u32 uVar1;
  
  uVar1 = FUN_001ee224();
  uVar1 = FUN_00065740(uVar1,DAT_002ec180,1);
  FUN_00217834(param_1 + 0x928,*(u32 *)(param_1 + 0x948),0xffffffff,uVar1);
  FUN_0021780c(param_1 + 0x928,uVar1,1.5f,1.0f);
}
