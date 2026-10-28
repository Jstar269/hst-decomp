/* HSTMATCH module=EBOOT.BIN start=0x000c787c end=0x000c7894 symbol=FUN_000c787c lang=c99 */
/* Clone of src/eboot/FUN_0008c230.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_000c787c(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = (unsigned int)(param_1 + 1);
  return param_1;
}
