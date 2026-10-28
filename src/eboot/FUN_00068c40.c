/* HSTMATCH module=EBOOT.BIN start=0x00068c40 end=0x00068c58 symbol=FUN_00068c40 lang=c99 */
/* Clone of src/eboot/FUN_0008c230.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00068c40(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = (unsigned int)(param_1 + 1);
  return param_1;
}
