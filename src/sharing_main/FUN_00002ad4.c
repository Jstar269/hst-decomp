/* HSTMATCH module=hstp_trans_main.prx start=0x00002ad4 end=0x00002ae8 symbol=FUN_00002ad4 lang=c99 */
/* Clone of src/eboot/FUN_0014c3f8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b01a4;

u32 * FUN_00002ad4(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b01a4);
  return param_1;
}
