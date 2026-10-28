/* HSTMATCH module=EBOOT.BIN start=0x0028007c end=0x00280088 symbol=FUN_0028007c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * FUN_00253974();

void FUN_0028007c(int param_1)
{
  FUN_00253974(2,*(u32 *)(param_1 + 8));
}
