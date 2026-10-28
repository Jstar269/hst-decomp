/* HSTMATCH module=EBOOT.BIN start=0x00056b98 end=0x00056bec symbol=FUN_00056b98 lang=c99 */
/* Clone of src/sharing_main/FUN_000577ec.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306ff8;
extern void FUN_00056d68();
extern u32 * FUN_0005eaa8();

u32 * FUN_00056b98(u32 *param_1)
{
  FUN_0005eaa8();
  *param_1 = (unsigned int)(&DAT_00306ff8);
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  FUN_00056d68(param_1);
  return param_1;
}
