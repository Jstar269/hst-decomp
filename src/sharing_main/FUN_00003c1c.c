/* HSTMATCH module=hstp_trans_main.prx start=0x00003c1c end=0x00003c50 symbol=FUN_00003c1c lang=c99 */
/* Clone of src/eboot/FUN_00155ea4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b01fc;
extern u32 * FUN_00003ae4();

u32 * FUN_00003c1c(u32 *param_1)
{
  FUN_00003ae4();
  *param_1 = (unsigned int)(&DAT_003b01fc);
  return param_1;
}
