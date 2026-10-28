/* HSTMATCH module=EBOOT.BIN start=0x000d83b8 end=0x000d8408 symbol=FUN_000d83b8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003075e0;
extern void FUN_000007f4();
extern void FUN_000d8408();
extern void FUN_000d8460();

u32 * FUN_000d83b8(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003075e0);
  FUN_000007f4((int)(param_1 + 1),FUN_000d8460,FUN_000d8408,0xc,6);
  return param_1;
}
