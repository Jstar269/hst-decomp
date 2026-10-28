/* HSTMATCH module=EBOOT.BIN start=0x00125d38 end=0x00125d74 symbol=FUN_00125d38 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00308018;
extern u32 * FUN_00060e2c();

u32 * FUN_00125d38(u32 *param_1)
{
  FUN_00060e2c();
  *param_1 = (unsigned int)(&DAT_00308018);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  return param_1;
}
