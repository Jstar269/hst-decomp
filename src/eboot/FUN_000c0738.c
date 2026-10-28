/* HSTMATCH module=EBOOT.BIN start=0x000c0738 end=0x000c07b8 symbol=FUN_000c0738 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the flag global typed as a byte; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307408;
extern u8 DAT_00338acc;
extern u32 DAT_00338ad0;
extern u32 * FUN_0001f06c();

u32 * FUN_000c0738(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00307408);
  param_1[0x1dc] = 0;
  param_1[0x1dd] = 0;
  param_1[0x1de] = 0;
  param_1[0x1df] = 0;
  param_1[0x1e0] = 0;
  param_1[0x1e1] = 0;
  param_1[0xf] = 1;
  param_1[0x10] = 0;
  param_1[0x1a5] = 0;
  DAT_00338acc = 0;
  DAT_00338ad0 = 0;
  *(u8 *)(param_1 + 0x11) = 0;
  param_1[0x1cb] = 0;
  param_1[0x1db] = 0;
  param_1[0x1e2] = 0;
  param_1[0x1e3] = 0;
  return param_1;
}
