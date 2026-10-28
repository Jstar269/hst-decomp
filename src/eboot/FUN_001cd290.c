/* HSTMATCH module=EBOOT.BIN start=0x001cd290 end=0x001cd29c symbol=FUN_001cd290 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_001cd290(int param_1)
{
  return *(u8 *)(*(int *)(param_1 + 0x15c) + 0xb0);
}
