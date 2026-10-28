/* HSTMATCH module=EBOOT.BIN start=0x00232c08 end=0x00232c58 symbol=FUN_00232c08 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a664;
extern void FUN_00232cc4();
extern void FUN_0023302c();

u32 * FUN_00232c08(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  DAT_0034a664 = (unsigned int)(param_1);
  *(u8 *)(param_1 + 4) = 0;
  *(u8 *)((int)param_1 + 0x11) = 0;
  *(u8 *)((int)param_1 + 0x12) = 0;
  FUN_00232cc4();
  FUN_0023302c(param_1,9);
  return param_1;
}
