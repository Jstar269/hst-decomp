/* HSTMATCH module=EBOOT.BIN start=0x002a0df4 end=0x002a0e08 symbol=FUN_002a0df4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002a0df4(int param_1,u16 param_2,u16 param_3,u16 param_4, u16 param_5)
{
  *(u16 *)(param_1 + 0xfc) = param_2;
  *(u16 *)(param_1 + 0xfe) = param_3;
  *(u16 *)(param_1 + 0x100) = param_4;
  *(u16 *)(param_1 + 0x102) = param_5;
}
