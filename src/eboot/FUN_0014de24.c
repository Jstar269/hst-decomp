/* HSTMATCH module=EBOOT.BIN start=0x0014de24 end=0x0014de6c symbol=FUN_0014de24 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003082f4;
extern u8 DAT_0030840c;
extern u16 FUN_0014f050();

u32 * FUN_0014de24(u32 *param_1,u32 param_2)
{
  *param_1 = (unsigned int)(&DAT_0030840c);
  *(u8 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_003082f4);
  FUN_0014f050(param_2);
  return param_1;
}
