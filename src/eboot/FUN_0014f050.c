/* HSTMATCH module=EBOOT.BIN start=0x0014f050 end=0x0014f064 symbol=FUN_0014f050 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u16 FUN_0014f050(u32 *param_1)
{
  u16 uVar1;
  
  uVar1 = *(u16 *)*param_1;
  *param_1 = (unsigned int)((u16 *)*param_1 + 1);
  return uVar1;
}
