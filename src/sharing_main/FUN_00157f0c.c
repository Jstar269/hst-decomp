/* HSTMATCH module=hstp_trans_main.prx start=0x00157f0c end=0x00157f20 symbol=FUN_00157f0c lang=c99 */
/* Clone of src/eboot/FUN_0014c3f8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b16b0;

u32 * FUN_00157f0c(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b16b0);
  return param_1;
}
