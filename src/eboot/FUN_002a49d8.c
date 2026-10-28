/* HSTMATCH module=EBOOT.BIN start=0x002a49d8 end=0x002a4a20 symbol=FUN_002a49d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309ee0;
extern u32 DAT_0034b350;
extern u32 * FUN_0001f06c();
extern void FUN_002a4f18();

u32 * FUN_002a49d8(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309ee0);
  DAT_0034b350 = (unsigned int)(param_1);
  FUN_002a4f18(param_1,0);
  return param_1;
}
