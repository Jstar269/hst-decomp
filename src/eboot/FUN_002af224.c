/* HSTMATCH module=EBOOT.BIN start=0x002af224 end=0x002af26c symbol=FUN_002af224 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();
extern u32 * FUN_000149a8();

void FUN_002af224(int param_1,u32 param_2)
{
  FUN_000114c0(param_1 + 0x1c,0,0x4b);
  FUN_000149a8(param_1 + 0x1c,param_2);
}
