/* HSTMATCH module=EBOOT.BIN start=0x000fafb8 end=0x000fafec symbol=FUN_000fafb8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;
extern void FUN_000f9290();

void FUN_000fafb8(int param_1)
{
  if (*(int *)(DAT_003386b0 + 0x3c) != 9) {
    FUN_000f9290(*(u32 *)(param_1 + 0x3c));
  }
}
