/* HSTMATCH module=EBOOT.BIN start=0x00286790 end=0x0028686c symbol=FUN_00286790 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: typed the four global values and destination fields as float; exact match verified; names and types await human review. */
#include "hst/types.h"

extern float DAT_002bc430;
extern float DAT_002bc434;
extern float DAT_002bc438;
extern float DAT_002bc43c;
extern u8 DAT_00309cac;
extern void FUN_00286d08();
extern u32 * FUN_00289654();

u32 * FUN_00286790(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00309cac);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  ((float *)param_1)[8] = DAT_002bc430;
  ((float *)param_1)[9] = DAT_002bc434;
  ((float *)param_1)[10] = DAT_002bc438;
  ((float *)param_1)[0xb] = DAT_002bc43c;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0xffffffff;
  param_1[0x10] = 0xffffffff;
  param_1[0x13] = 0xffffffff;
  param_1[0x14] = 0x3fc00000;
  *(u8 *)(param_1 + 0x15) = 1;
  *(u8 *)((int)param_1 + 0x55) = 0;
  *(u8 *)((int)param_1 + 0x56) = 0;
  *(u8 *)((int)param_1 + 0x57) = 1;
  *(u8 *)(param_1 + 0x16) = 0;
  *(u8 *)((int)param_1 + 0x59) = 0;
  *(u8 *)((int)param_1 + 0x5a) = 0;
  *(u8 *)((int)param_1 + 0x5b) = 0;
  *(u8 *)(param_1 + 0x17) = 0;
  param_1[0x18] = 0;
  FUN_00289654(param_1 + 0x19);
  FUN_00286d08(param_1);
  param_1[0x11] = 0x3f800000;
  param_1[0x12] = 0x3f800000;
  return param_1;
}

