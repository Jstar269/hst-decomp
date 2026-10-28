/* HSTMATCH module=EBOOT.BIN start=0x00155604 end=0x0015562c symbol=FUN_00155604 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00288828();

u32 FUN_00155604(int param_1)
{
  FUN_00288828(*(u32 *)(param_1 + 8),*(u32 *)(param_1 + 0xc),1000);
  return 0;
}
