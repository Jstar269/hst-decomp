/* HSTMATCH module=EBOOT.BIN start=0x00114168 end=0x00114178 symbol=FUN_00114168 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00114190();

void FUN_00114168(int param_1)
{
  *(u8 *)(*(int *)(param_1 + 0x54) + 0x90a) = 1;
  FUN_00114190();
}
