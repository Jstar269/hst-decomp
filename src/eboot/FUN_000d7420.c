/* HSTMATCH module=EBOOT.BIN start=0x000d7420 end=0x000d7458 symbol=FUN_000d7420 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();

void FUN_000d7420(u32 param_1,u32 *param_2)
{
  if (((param_2 != (u32 *)0x0) && (param_2 != (u32 *)0x0)) && ((*param_2 & 1) != 0)) {
    FUN_00000a00(param_2[2]);
  }
}
