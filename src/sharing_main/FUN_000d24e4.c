/* HSTMATCH module=hstp_trans_main.prx start=0x000d24e4 end=0x000d2508 symbol=FUN_000d24e4 lang=c99 */
/* Clone of src/eboot/FUN_000ce8e8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0808;
extern u8 DAT_003b081c;

u32 * FUN_000d24e4(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b0808);
  param_1[1] = 0;
  *param_1 = (unsigned int)(&DAT_003b081c);
  return param_1;
}
