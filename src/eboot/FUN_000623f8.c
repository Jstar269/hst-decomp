/* HSTMATCH module=EBOOT.BIN start=0x000623f8 end=0x00062418 symbol=FUN_000623f8 lang=c99 */
/* Clone of src/sharing_main/FUN_000632e4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_000623f8(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0xffffffff;
  *(u8 *)(param_1 + 2) = 0;
  param_1[3] = 0xffffffff;
  param_1[4] = 0;
  return param_1;
}
