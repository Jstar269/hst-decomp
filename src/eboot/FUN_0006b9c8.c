/* HSTMATCH module=EBOOT.BIN start=0x0006b9c8 end=0x0006b9e8 symbol=FUN_0006b9c8 lang=c99 */
/* Clone of src/sharing_main/FUN_0006cfb0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0006b9c8(u32 *param_1,u8 *param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(u8 *)(param_1 + 2) = *param_2;
  param_1[3] = (unsigned int)(param_1 + 1);
  return param_1;
}
