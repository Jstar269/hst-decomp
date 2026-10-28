/* HSTMATCH module=EBOOT.BIN start=0x000dcd64 end=0x000dcd6c symbol=FUN_000dcd64 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000dcd64(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0xac) = param_2;
}
