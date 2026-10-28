/* HSTMATCH module=EBOOT.BIN start=0x00045730 end=0x0004577c symbol=FUN_00045730 lang=c99 */
/* Clone of src/sharing_main/FUN_00045830.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000458d0();
extern void FUN_000459f8();

u32 * FUN_00045730(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  FUN_000459f8(param_1 + 3);
  FUN_000458d0(param_1);
  return param_1;
}
