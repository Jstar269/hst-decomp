/* HSTMATCH module=EBOOT.BIN start=0x002b4d94 end=0x002b4d9c symbol=FUN_002b4d94 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_002aff18(u32 *param_1,short param_2);

void FUN_002b4d94(int param_1,short param_2)
{
  FUN_002aff18((u32 *)((u32 *)(param_1 + -0x3c)),(short)(param_2));
}
