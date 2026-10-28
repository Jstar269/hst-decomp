/* HSTMATCH module=hstp_trans_main.prx start=0x001dbeec end=0x001dbf18 symbol=FUN_001dbeec lang=c99 */
/* Clone of src/eboot/FUN_001cd810.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b261c;

u32 * FUN_001dbeec(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b261c);
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}
