/* HSTMATCH module=EBOOT.BIN start=0x0004a158 end=0x0004a1a4 symbol=FUN_0004a158 lang=c99 */
/* Clone of src/sharing_main/FUN_0004a128.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();

u32 * FUN_0004a158(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[7] = 0;
  param_1[8] = 0xffffffff;
  FUN_000114c0(param_1 + 3,0,0x10);
  return param_1;
}
