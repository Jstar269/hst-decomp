/* HSTMATCH module=EBOOT.BIN start=0x00280088 end=0x00280094 symbol=FUN_00280088 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * FUN_00253974();

void FUN_00280088(int param_1)
{
  FUN_00253974(3,*(u32 *)(param_1 + 0xc));
}
