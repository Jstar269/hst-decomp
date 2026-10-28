/* HSTMATCH module=hstp_trans_main.prx start=0x002a4a48 end=0x002a4a94 symbol=FUN_002a4a48 lang=c99 */
/* Clone of src/eboot/FUN_0029343c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b30d4;
extern u32 * FUN_00297ebc();

u32 * FUN_002a4a48(u32 *param_1)
{
  FUN_00297ebc();
  *param_1 = (unsigned int)(&DAT_003b30d4);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0xffffffff;
  return param_1;
}
