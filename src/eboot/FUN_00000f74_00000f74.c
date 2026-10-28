/* HSTMATCH module=EBOOT.BIN start=0x00000f74 end=0x00000f98 symbol=FUN_00000f74 lang=c99 */
/* Clone of src/sharing_main/FUN_00000f74.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0030a03c;

u32 FUN_00000f74(u32 param_1,u32 param_2,u32 *param_3)
{
  *param_3 = DAT_0030a03c;
  param_3[1] = param_2;
  param_3[2] = param_1;
  DAT_0030a03c = (unsigned int)(param_3);
  return param_1;
}
