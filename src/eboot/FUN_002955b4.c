/* HSTMATCH module=EBOOT.BIN start=0x002955b4 end=0x002955c8 symbol=FUN_002955b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010b8cc();

void FUN_002955b4(int param_1)
{
  FUN_0010b8cc(**(u32 **)(param_1 + 0x58),0,0);
}
