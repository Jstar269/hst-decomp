/* HSTMATCH module=EBOOT.BIN start=0x00002d8c end=0x00002d9c symbol=FUN_00002d8c lang=c99 */
/* Clone of src/sharing_main/FUN_00002d8c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00002d8c(u32 *param_1,u32 param_2,u32 param_3)
{
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}
