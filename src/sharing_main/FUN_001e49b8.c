/* HSTMATCH module=hstp_trans_main.prx start=0x001e49b8 end=0x001e49e0 symbol=FUN_001e49b8 lang=c99 */
/* Clone of src/eboot/FUN_001d6bc8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2f7c;
extern u8 DAT_003b2f88;

u32 * FUN_001e49b8(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b2f88);
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = (unsigned int)(&DAT_003b2f7c);
  return param_1;
}
