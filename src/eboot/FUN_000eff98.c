/* HSTMATCH module=EBOOT.BIN start=0x000eff98 end=0x000effa0 symbol=FUN_000eff98 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000eff98(int param_1,u16 param_2)
{
  *(u16 *)(param_1 + 0x104) = param_2;
}
