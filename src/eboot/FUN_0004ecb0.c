/* HSTMATCH module=EBOOT.BIN start=0x0004ecb0 end=0x0004ecbc symbol=FUN_0004ecb0 lang=c99 */
/* Clone of src/eboot/FUN_0027c750.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0032b240;
extern void FUN_0004eaf8();

void FUN_0004ecb0(u32 param_1)
{
  FUN_0004eaf8(param_1,DAT_0032b240);
}
