/* HSTMATCH module=EBOOT.BIN start=0x001da160 end=0x001da168 symbol=FUN_001da160 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_001da160(int param_1)
{
  return *(u8 *)(param_1 + 0x55);
}
