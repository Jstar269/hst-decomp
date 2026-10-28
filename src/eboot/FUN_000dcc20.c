/* HSTMATCH module=EBOOT.BIN start=0x000dcc20 end=0x000dcc3c symbol=FUN_000dcc20 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000dcc20(int param_1,u32 param_2,u32 param_3)
{
  if (*(u8 *)(param_1 + 0x44) != '\0') {
    *(u32 *)(param_1 + 0x68) = param_2;
    *(u32 *)(param_1 + 0x6c) = param_3;
  }
}
