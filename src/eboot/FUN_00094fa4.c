/* HSTMATCH module=EBOOT.BIN start=0x00094fa4 end=0x00094fe0 symbol=FUN_00094fa4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307278;
extern u32 * FUN_00056b98();
extern void FUN_0009503c();

u32 * FUN_00094fa4(u32 *param_1)
{
  FUN_00056b98();
  *param_1 = (unsigned int)(&DAT_00307278);
  FUN_0009503c(param_1);
  return param_1;
}
