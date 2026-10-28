/* HSTMATCH module=EBOOT.BIN start=0x000d4cd4 end=0x000d4d34 symbol=FUN_000d4cd4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030744c;
extern void FUN_000007f4();
extern u32 * FUN_0001f06c();
extern void FUN_000d4ddc();
extern void FUN_00056b98();
extern void FUN_00056cb0();

u32 * FUN_000d4cd4(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_0030744c);
  FUN_000007f4(param_1 + 0x14,FUN_00056b98,FUN_00056cb0,0x1b0,4);
  *(u8 *)(param_1 + 0x1c4) = 0;
  FUN_000d4ddc(param_1);
  return param_1;
}
