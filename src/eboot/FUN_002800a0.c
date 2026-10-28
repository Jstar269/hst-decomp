/* HSTMATCH module=EBOOT.BIN start=0x002800a0 end=0x002800ac symbol=FUN_002800a0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * FUN_00253974();

void FUN_002800a0(int param_1)
{
  FUN_00253974(5,*(u32 *)(param_1 + 0x14));
}
