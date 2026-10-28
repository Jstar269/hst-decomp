/* HSTMATCH module=EBOOT.BIN start=0x000fbed0 end=0x000fbee4 symbol=FUN_000fbed0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000fbed0(int param_1,int param_2)
{
  *(char *)(param_1 + 0x58) = (char)param_2;
  if (param_2 != 0) {
    *(u32 *)(param_1 + 0x5c) = 0;
  }
}
