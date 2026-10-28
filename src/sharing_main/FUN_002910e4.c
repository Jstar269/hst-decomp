/* HSTMATCH module=hstp_trans_main.prx start=0x002910e4 end=0x00291130 symbol=FUN_002910e4 lang=c99 */
/* Clone of src/eboot/FUN_0027fc70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002db018;

void FUN_002910e4(u32 *param_1,u32 *param_2,u32 param_3)
{
  *param_2 = *param_2 & 0xffffff | (u32)(u8)(&DAT_002db018)[*param_1 % 0x1e] << 0x18;
  *param_1 = *param_1 + (param_3 & 0xff);
}
