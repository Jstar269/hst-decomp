/* HSTMATCH module=hstp_trans_main.prx start=0x000c1e3c end=0x000c1e54 symbol=FUN_000c1e3c lang=c99 */
/* Clone of src/eboot/FUN_000be79c.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0698;

u32 * FUN_000c1e3c(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b0698);
  param_1[6] = 0;
  return param_1;
}
