/* HSTMATCH module=hstp_trans_main.prx start=0x0020a014 end=0x0020a040 symbol=FUN_0020a014 lang=c99 */
/* Clone of src/eboot/FUN_001cd810.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b27dc;

u32 * FUN_0020a014(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b27dc);
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}
