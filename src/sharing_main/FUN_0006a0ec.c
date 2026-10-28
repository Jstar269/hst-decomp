/* HSTMATCH module=hstp_trans_main.prx start=0x0006a0ec end=0x0006a104 symbol=FUN_0006a0ec lang=c99 */
/* Clone of src/eboot/FUN_0008c230.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0006a0ec(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = (unsigned int)(param_1 + 1);
  return param_1;
}
