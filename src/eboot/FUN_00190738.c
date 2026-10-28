/* HSTMATCH module=EBOOT.BIN start=0x00190738 end=0x00190744 symbol=FUN_00190738 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_00190738(int param_1)
{
  return *(u8 *)(*(int *)(param_1 + 0x3c) + 0xac);
}
