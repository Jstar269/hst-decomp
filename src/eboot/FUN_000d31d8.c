/* HSTMATCH module=EBOOT.BIN start=0x000d31d8 end=0x000d3204 symbol=FUN_000d31d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000e7198();

void FUN_000d31d8(int param_1)
{
  if (*(u8 *)(*(int *)(param_1 + 0x180) + 0xd0) != '\0') {
    FUN_000e7198(*(int *)(param_1 + 0x180),0);
  }
}
