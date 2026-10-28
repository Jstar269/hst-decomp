/* HSTMATCH module=EBOOT.BIN start=0x001fc31c end=0x001fc374 symbol=FUN_001fc31c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309534;
extern u32 * FUN_0001f06c();
extern void FUN_001fc718();

u32 * FUN_001fc31c(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309534);
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  FUN_001fc718(param_1,5);
  param_1[0x14] = 0;
  *(u8 *)(param_1 + 0x15) = 0;
  return param_1;
}
