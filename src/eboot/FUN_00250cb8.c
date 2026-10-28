/* HSTMATCH module=EBOOT.BIN start=0x00250cb8 end=0x00250cc4 symbol=FUN_00250cb8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00250cb8(int param_1)
{
  *(u32 *)(param_1 + 0x31c) = 0;
  *(u32 *)(param_1 + 800) = 0;
}
