/* HSTMATCH module=EBOOT.BIN start=0x00067b28 end=0x00067b40 symbol=FUN_00067b28 lang=c99 */
/* Clone of src/eboot/FUN_0014f314.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00067b28(u32 *param_1)
{
  *param_1 = 0;
  param_1[2] = (unsigned int)(param_1 + 1);
  param_1[1] = (unsigned int)(param_1 + 1);
  return param_1;
}
