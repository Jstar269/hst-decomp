/* HSTMATCH module=EBOOT.BIN start=0x000fba28 end=0x000fba88 symbol=FUN_000fba28 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307744;
extern u32 DAT_00338c24;
extern u32 * FUN_0001f06c();

u32 * FUN_000fba28(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00307744);
  param_1[0xf] = 0;
  DAT_00338c24 = (unsigned int)(param_1);
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  *(u8 *)(param_1 + 0x16) = 0;
  param_1[0x17] = 0;
  return param_1;
}
