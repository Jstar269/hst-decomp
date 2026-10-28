/* HSTMATCH module=EBOOT.BIN start=0x000f3948 end=0x000f397c symbol=FUN_000f3948 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000f3948(int param_1)
{
  *(u32 *)(param_1 + 0x1e0) = *(u32 *)(*(int *)(param_1 + 0x128) + 0x24);
  *(u32 *)(param_1 + 0x1e4) = *(u32 *)(*(int *)(param_1 + 300) + 0x24);
  *(u32 *)(param_1 + 0x1e8) = *(u32 *)(*(int *)(param_1 + 0x138) + 0x24);
  *(u32 *)(param_1 + 0x1ec) = *(u32 *)(*(int *)(param_1 + 0x13c) + 0x24);
}
