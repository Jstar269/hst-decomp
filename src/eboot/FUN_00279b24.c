/* HSTMATCH module=EBOOT.BIN start=0x00279b24 end=0x00279b34 symbol=FUN_00279b24 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00279b24(int param_1)
{
  *(u32 *)(param_1 + 0x45c) = 0x1e;
  *(u8 *)(param_1 + 0x454) = 0;
}
