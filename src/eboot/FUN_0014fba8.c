/* HSTMATCH module=EBOOT.BIN start=0x0014fba8 end=0x0014fbd4 symbol=FUN_0014fba8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0028867c();

u32 FUN_0014fba8(int param_1)
{
  FUN_0028867c(*(u32 *)(param_1 + 8),*(u32 *)(param_1 + 0xc),
               *(u32 *)(param_1 + 0x10));
  return 0;
}
