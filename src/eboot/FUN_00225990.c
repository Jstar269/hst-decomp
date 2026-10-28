/* HSTMATCH module=EBOOT.BIN start=0x00225990 end=0x0022599c symbol=FUN_00225990 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0021b088();

void FUN_00225990(int param_1)
{
  FUN_0021b088(**(u32 **)(param_1 + 0x3c));
}
