/* HSTMATCH module=EBOOT.BIN start=0x001b9760 end=0x001b97a4 symbol=FUN_001b9760 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003092f8;
extern u32 * FUN_0001f06c();

u32 * FUN_001b9760(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_003092f8);
  param_1[0xf] = 0;
  *(u8 *)(param_1 + 0x10) = 0;
  *(u8 *)((int)param_1 + 0x41) = 0;
  param_1[0x11] = 0;
  return param_1;
}
