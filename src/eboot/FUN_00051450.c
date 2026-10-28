/* HSTMATCH module=EBOOT.BIN start=0x00051450 end=0x00051464 symbol=FUN_00051450 lang=c99 */
/* Clone of src/sharing_main/FUN_00051df0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00311170;
extern u32 FUN_0004ffc4();

void FUN_00051450(int param_1)
{
  FUN_0004ffc4((int)&DAT_00311170,*(u32 *)(param_1 + 4),0);
}
