/* HSTMATCH module=EBOOT.BIN start=0x0009503c end=0x00095058 symbol=FUN_0009503c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0009503c(int param_1)
{
  *(u32 *)(param_1 + 0x1b0) = 6;
  *(u32 *)(param_1 + 0x1b4) = 0xffffffff;
  *(u16 *)(param_1 + 0x1b8) = 0;
  *(u8 *)(param_1 + 0x1ba) = 0;
}
