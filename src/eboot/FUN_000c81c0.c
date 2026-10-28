/* HSTMATCH module=EBOOT.BIN start=0x000c81c0 end=0x000c81ec symbol=FUN_000c81c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a3); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000ce72c();

u32 FUN_000c81c0(int param_1)
{
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_000ce72c(*(int *)(param_1 + 0x44));
  }
  return 1;
}
