/* HSTMATCH module=EBOOT.BIN start=0x0027b8c4 end=0x0027b8cc symbol=FUN_0027b8c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_0026ce14(u32 *param_1,short param_2);

void FUN_0027b8c4(int param_1,short param_2)
{
  FUN_0026ce14((u32 *)((u32 *)(param_1 + -0x3c)),(short)(param_2));
}
