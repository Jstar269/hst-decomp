/* HSTMATCH module=EBOOT.BIN start=0x0027fc70 end=0x0027fcbc symbol=FUN_0027fc70 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002caa58;

void FUN_0027fc70(u32 *param_1,u32 *param_2,u32 param_3)
{
  *param_2 = *param_2 & 0xffffff | (u32)(u8)(&DAT_002caa58)[*param_1 % 0x1e] << 0x18;
  *param_1 = *param_1 + (param_3 & 0xff);
}
