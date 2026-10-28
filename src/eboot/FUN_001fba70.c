/* HSTMATCH module=EBOOT.BIN start=0x001fba70 end=0x001fba78 symbol=FUN_001fba70 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_001ee998(u32 *param_1,short param_2);

void FUN_001fba70(int param_1,short param_2)
{
  FUN_001ee998((u32 *)((u32 *)(param_1 + -0x3c)),(short)(param_2));
}
