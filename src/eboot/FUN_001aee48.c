/* HSTMATCH module=EBOOT.BIN start=0x001aee48 end=0x001aee54 symbol=FUN_001aee48 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_001aee48(int param_1)
{
  return *(u8 *)(*(int *)(param_1 + 8) + 0xaa4);
}
