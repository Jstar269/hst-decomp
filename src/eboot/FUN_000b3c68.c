/* HSTMATCH module=EBOOT.BIN start=0x000b3c68 end=0x000b3ca0 symbol=FUN_000b3c68 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00341508;

int FUN_000b3c68(int param_1)
{
  return *(int *)(DAT_00341508 + *(int *)(param_1 + 0x158) * 0x18) +
         *(int *)(param_1 + 0x15c) * 0x22c;
}
