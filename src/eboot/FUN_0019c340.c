/* HSTMATCH module=EBOOT.BIN start=0x0019c340 end=0x0019c384 symbol=FUN_0019c340 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309250;
extern u32 DAT_003415d4;
extern u32 * FUN_0001f06c();
extern void FUN_001905b8();

u32 * FUN_0019c340(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309250);
  FUN_001905b8(DAT_003415d4,1);
  return param_1;
}
