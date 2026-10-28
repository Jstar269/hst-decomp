/* HSTMATCH module=EBOOT.BIN start=0x00056198 end=0x000561d4 symbol=FUN_00056198 lang=c99 */
/* Clone of src/sharing_main/FUN_00056dac.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000562b8();

u32 * FUN_00056198(u32 *param_1,u32 param_2)
{
  FUN_000562b8(param_1);
  *param_1 = param_2;
  *(u8 *)(param_1 + 2) = 0;
  return param_1;
}
