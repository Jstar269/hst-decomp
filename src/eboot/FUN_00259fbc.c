/* HSTMATCH module=EBOOT.BIN start=0x00259fbc end=0x00259ffc symbol=FUN_00259fbc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003417c4;
extern void FUN_001b4dfc();
extern void FUN_00255674();
extern int FUN_00285c78();

void FUN_00259fbc(int param_1)
{
  u32 uVar1;
  
  FUN_001b4dfc(DAT_003417c4);
  uVar1 = FUN_00285c78(*(u32 *)(param_1 + 0x640));
  FUN_00255674(param_1 + 0x60,uVar1);
}
