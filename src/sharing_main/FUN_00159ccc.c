/* HSTMATCH module=hstp_trans_main.prx start=0x00159ccc end=0x00159d14 symbol=FUN_00159ccc lang=c99 */
/* Clone of src/eboot/FUN_0014de24.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b15c0;
extern u8 DAT_003b16d8;
extern u16 FUN_0015b050();

u32 * FUN_00159ccc(u32 *param_1,u32 param_2)
{
  *param_1 = (unsigned int)(&DAT_003b16d8);
  *(u8 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_003b15c0);
  FUN_0015b050(param_2);
  return param_1;
}
