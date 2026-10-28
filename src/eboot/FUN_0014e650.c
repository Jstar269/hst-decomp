/* HSTMATCH module=EBOOT.BIN start=0x0014e650 end=0x0014e698 symbol=FUN_0014e650 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030829c;
extern u8 DAT_0030840c;
extern u16 FUN_0014f050();

u32 * FUN_0014e650(u32 *param_1,u32 param_2)
{
  *param_1 = (unsigned int)(&DAT_0030840c);
  *(u8 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_0030829c);
  FUN_0014f050(param_2);
  return param_1;
}
