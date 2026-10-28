/* HSTMATCH module=hstp_trans_main.prx start=0x002411d0 end=0x00241214 symbol=FUN_002411d0 lang=c99 */
/* Clone of src/eboot/FUN_002310d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f398c;
extern void FUN_00241268();
extern void FUN_00241348();

u32 * FUN_002411d0(u32 *param_1,u8 param_2)
{
  *param_1 = 0;
  DAT_003f398c = (unsigned int)(param_1);
  *(u8 *)(param_1 + 2) = param_2;
  FUN_00241268();
  FUN_00241348(param_1,1);
  return param_1;
}
