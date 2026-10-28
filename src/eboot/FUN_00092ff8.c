/* HSTMATCH module=EBOOT.BIN start=0x00092ff8 end=0x00093024 symbol=FUN_00092ff8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00093024();
extern void FUN_0009306c();

void FUN_00092ff8(u32 param_1)
{
  FUN_00093024();
  FUN_0009306c(param_1);
}
