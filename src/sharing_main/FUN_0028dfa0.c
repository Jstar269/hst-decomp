/* HSTMATCH module=hstp_trans_main.prx start=0x0028dfa0 end=0x0028dfe4 symbol=FUN_0028dfa0 lang=c99 */
/* Clone of src/eboot/FUN_0027cc30.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2f00;
extern u32 * FUN_0001ec44();

u32 * FUN_0028dfa0(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b2f00);
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  return param_1;
}
