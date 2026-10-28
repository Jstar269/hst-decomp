/* HSTMATCH module=EBOOT.BIN start=0x000b91fc end=0x000b9208 symbol=FUN_000b91fc lang=c99 */
/* Clone of src/eboot/FUN_0027c750.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003313c4;
extern void FUN_000b8e2c();

void FUN_000b91fc(u32 param_1)
{
  FUN_000b8e2c(param_1,DAT_003313c4);
}
