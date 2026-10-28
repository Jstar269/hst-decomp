/* HSTMATCH module=EBOOT.BIN start=0x0029343c end=0x00293488 symbol=FUN_0029343c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309dec;
extern u32 * FUN_00286790();

u32 * FUN_0029343c(u32 *param_1)
{
  FUN_00286790();
  *param_1 = (unsigned int)(&DAT_00309dec);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0xffffffff;
  return param_1;
}
