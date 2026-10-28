/* HSTMATCH module=EBOOT.BIN start=0x00253d00 end=0x00253d30 symbol=FUN_00253d00 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00253d30();

int FUN_00253d00(int param_1)
{
  FUN_00253d30();
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
