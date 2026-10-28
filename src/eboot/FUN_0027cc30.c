/* HSTMATCH module=EBOOT.BIN start=0x0027cc30 end=0x0027cc74 symbol=FUN_0027cc30 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309c18;
extern u32 * FUN_0001f06c();

u32 * FUN_0027cc30(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309c18);
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  return param_1;
}
