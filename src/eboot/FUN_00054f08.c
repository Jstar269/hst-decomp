/* HSTMATCH module=EBOOT.BIN start=0x00054f08 end=0x00054f4c symbol=FUN_00054f08 lang=c99 */
/* Clone of src/sharing_main/FUN_00055a28.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306fd4;
extern void FUN_00054fb0();

u32 * FUN_00054f08(u32 *param_1,u32 param_2)
{
  *param_1 = (unsigned int)(&DAT_00306fd4);
  FUN_00054fb0();
  param_1[0x23] = param_2;
  return param_1;
}
