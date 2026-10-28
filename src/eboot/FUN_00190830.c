/* HSTMATCH module=EBOOT.BIN start=0x00190830 end=0x0019083c symbol=FUN_00190830 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00190830(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x3c) + 0x280);
}
