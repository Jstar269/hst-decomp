/* HSTMATCH module=EBOOT.BIN start=0x00190304 end=0x00190348 symbol=FUN_00190304 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309194;
extern u32 * FUN_0001f06c();
extern void FUN_00198df0();
extern void FUN_00198eb4();

u32 * FUN_00190304(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309194);
  FUN_00198df0(param_1 + 0xf);
  FUN_00198eb4(param_1);
  return param_1;
}
