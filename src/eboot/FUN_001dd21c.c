/* HSTMATCH module=EBOOT.BIN start=0x001dd21c end=0x001dd260 symbol=FUN_001dd21c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103480();
extern void FUN_001ea8dc();
extern void FUN_001ea930();
extern void FUN_001eaa00();

void FUN_001dd21c(int param_1)
{
  FUN_00103480();
  FUN_001ea930(*(u32 *)(param_1 + 0x8c),0);
  FUN_001eaa00(*(u32 *)(param_1 + 0x8c),0);
  FUN_001ea8dc(*(u32 *)(param_1 + 0x8c));
}
