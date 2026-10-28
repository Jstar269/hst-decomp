/* HSTMATCH module=EBOOT.BIN start=0x0013fb50 end=0x0013fb58 symbol=FUN_0013fb50 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_001323e8(u32 *param_1,short param_2);

void FUN_0013fb50(int param_1,short param_2)
{
  FUN_001323e8((u32 *)((u32 *)(param_1 + -0x40)),(short)(param_2));
}
