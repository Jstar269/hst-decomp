/* HSTMATCH module=EBOOT.BIN start=0x00266d24 end=0x00266d94 symbol=FUN_00266d24 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309b58;
extern u32 DAT_003402a0;
extern u32 * FUN_0001f06c();

u32 * FUN_00266d24(u32 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309b58);
  param_1[0xf] = 0;
  param_1[0x12] = 0;
  *(u8 *)(param_1 + 0x13) = 1;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  *(u8 *)(param_1 + 0x19) = 0;
  if (*(int *)(DAT_003402a0 + 0x1364) == 6) {
    *(u8 *)((int)param_1 + 0x65) = 1;
  }
  else {
    *(u8 *)((int)param_1 + 0x65) = 0;
  }
  return param_1;
}
