/* HSTMATCH module=EBOOT.BIN start=0x00291a80 end=0x00291aec symbol=FUN_00291a80 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309ddc;

u32 * FUN_00291a80(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00309ddc);
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[5] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0x3f800000;
  *(u8 *)(param_1 + 0x10) = 0;
  *(u8 *)((int)param_1 + 0x41) = 0;
  param_1[0x11] = 2;
  param_1[0x12] = 0;
  return param_1;
}
