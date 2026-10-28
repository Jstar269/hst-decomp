/* HSTMATCH module=EBOOT.BIN start=0x0006ce30 end=0x0006ce70 symbol=FUN_0006ce30 lang=c99 */
/* Clone of src/sharing_main/FUN_0006e418.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0006b6f8();

u32 * FUN_0006ce30(u32 *param_1,int param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(u8 *)(param_1 + 2) = *(u8 *)(param_2 + 8);
  param_1[3] = (unsigned int)(param_1 + 1);
  FUN_0006b6f8();
  return param_1;
}
