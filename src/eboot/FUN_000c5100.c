/* HSTMATCH module=EBOOT.BIN start=0x000c5100 end=0x000c5110 symbol=FUN_000c5100 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000c5100(int param_1)
{
  *(u8 *)(*(int *)(param_1 + 0x784) + 4) = 1;
}
