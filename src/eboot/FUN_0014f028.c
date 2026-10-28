/* HSTMATCH module=EBOOT.BIN start=0x0014f028 end=0x0014f03c symbol=FUN_0014f028 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_0014f028(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = *(u32 *)*param_1;
  *param_1 = (unsigned int)((u32 *)*param_1 + 1);
  return uVar1;
}
