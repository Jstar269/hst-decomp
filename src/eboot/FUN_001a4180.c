/* HSTMATCH module=EBOOT.BIN start=0x001a4180 end=0x001a41ac symbol=FUN_001a4180 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001a41b4();
extern void FUN_001a429c();

void FUN_001a4180(u32 param_1)
{
  FUN_001a41b4();
  FUN_001a429c(param_1);
}
