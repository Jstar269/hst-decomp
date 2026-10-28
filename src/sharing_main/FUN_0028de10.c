/* HSTMATCH module=hstp_trans_main.prx start=0x0028de10 end=0x0028de54 symbol=FUN_0028de10 lang=c99 */
/* Clone of src/eboot/FUN_0027caa0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2f1c;
extern u32 * FUN_00061cb0();

u32 * FUN_0028de10(u32 *param_1)
{
  FUN_00061cb0();
  *param_1 = (unsigned int)(&DAT_003b2f1c);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x21] = 0x40000000;
  return param_1;
}
