/* HSTMATCH module=EBOOT.BIN start=0x0028e02c end=0x0028e074 symbol=FUN_0028e02c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415ac;
extern void FUN_00103628();
extern void FUN_00281090();

void FUN_0028e02c(int param_1)
{
  *(u8 *)(param_1 + 0x54) = 0;
  *(u8 *)(param_1 + 0x55) = 0;
  FUN_00103628(param_1,1);
  FUN_00103628(DAT_003415ac,1);
  FUN_00281090(*(u32 *)(param_1 + 0x640));
}
