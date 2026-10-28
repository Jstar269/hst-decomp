/* HSTMATCH module=EBOOT.BIN start=0x00292e60 end=0x00292eac symbol=FUN_00292e60 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309dcc;
extern u32 * FUN_00291a80();

u32 * FUN_00292e60(u32 *param_1)
{
  FUN_00291a80();
  *param_1 = (unsigned int)(&DAT_00309dcc);
  *(u8 *)(param_1 + 0x13) = 0;
  *(u8 *)((int)param_1 + 0x4d) = 0;
  param_1[0x14] = 0;
  *(u8 *)(param_1 + 0x15) = 0;
  *(u8 *)((int)param_1 + 0x4e) = 1;
  return param_1;
}
