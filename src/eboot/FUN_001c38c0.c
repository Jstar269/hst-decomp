/* HSTMATCH module=EBOOT.BIN start=0x001c38c0 end=0x001c38e0 symbol=FUN_001c38c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001c38c0(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x61) = param_2;
  if (*(u8 *)(param_1 + 0x61) != '\0') {
    *(u8 *)(param_1 + 0x62) = 1;
  }
}
