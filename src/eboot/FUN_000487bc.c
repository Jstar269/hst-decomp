/* HSTMATCH module=EBOOT.BIN start=0x000487bc end=0x000487c8 symbol=FUN_000487bc lang=c99 */
/* Clone of src/eboot/FUN_0008d958.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00311060;

void FUN_000487bc(u32 param_1)
{
  DAT_00311060 = param_1;
}
