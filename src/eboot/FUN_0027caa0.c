/* HSTMATCH module=EBOOT.BIN start=0x0027caa0 end=0x0027cae4 symbol=FUN_0027caa0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309c34;
extern u32 * FUN_00060e2c();

u32 * FUN_0027caa0(u32 *param_1)
{
  FUN_00060e2c();
  *param_1 = (unsigned int)(&DAT_00309c34);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x21] = 0x40000000;
  return param_1;
}
