/* HSTMATCH module=hstp_trans_main.prx start=0x00104d94 end=0x00104de0 symbol=FUN_00104d94 lang=c99 */
/* Clone of src/eboot/FUN_000ff4fc.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0c40;
extern int FUN_00010184();

u32 * FUN_00104d94(u32 *param_1,u32 param_2)
{
  u32 uVar1;
  
  *param_1 = (unsigned int)(&DAT_003b0c40);
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar1 = FUN_00010184(0x40);
  param_1[1] = uVar1;
  return param_1;
}
