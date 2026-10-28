/* HSTMATCH module=EBOOT.BIN start=0x002310d0 end=0x00231114 symbol=FUN_002310d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a65c;
extern void FUN_00231168();
extern void FUN_00231248();

u32 * FUN_002310d0(u32 *param_1,u8 param_2)
{
  *param_1 = 0;
  DAT_0034a65c = (unsigned int)(param_1);
  *(u8 *)(param_1 + 2) = param_2;
  FUN_00231168();
  FUN_00231248(param_1,1);
  return param_1;
}
