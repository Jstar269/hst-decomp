/* HSTMATCH module=hstp_trans_main.prx start=0x00130f6c end=0x00130fa8 symbol=FUN_00130f6c lang=c99 */
/* Clone of src/eboot/FUN_00125d38.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b12e4;
extern u32 * FUN_00061cb0();

u32 * FUN_00130f6c(u32 *param_1)
{
  FUN_00061cb0();
  *param_1 = (unsigned int)(&DAT_003b12e4);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  return param_1;
}
