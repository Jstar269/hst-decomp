/* HSTMATCH module=EBOOT.BIN start=0x000dcc54 end=0x000dcc6c symbol=FUN_000dcc54 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000dcc54(int param_1,u32 param_2)
{
  if (*(u8 *)(param_1 + 0x44) != '\0') {
    *(u32 *)(param_1 + 0x7c) = param_2;
  }
}
