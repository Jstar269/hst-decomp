/* HSTMATCH module=hstp_trans_main.prx start=0x002bd694 end=0x002bd6a8 symbol=FUN_002bd694 lang=c99 */
/* Clone of src/eboot/FUN_002ade6c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f4910;

u32 * FUN_002bd694(u32 *param_1)
{
  *param_1 = 0;
  DAT_003f4910 = (unsigned int)(param_1);
  return param_1;
}
