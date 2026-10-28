/* HSTMATCH module=EBOOT.BIN start=0x001268b8 end=0x001268c4 symbol=FUN_001268b8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000ff678();

void FUN_001268b8(int param_1,u32 param_2,u32 param_3)
{
  FUN_000ff678(*(u32 *)(param_1 + 0x1c),param_2,param_3,1);
}
