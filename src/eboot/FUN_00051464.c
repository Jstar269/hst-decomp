/* HSTMATCH module=EBOOT.BIN start=0x00051464 end=0x00051478 symbol=FUN_00051464 lang=c99 */
/* Clone of src/sharing_main/FUN_00051df0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00311170;
extern u32 FUN_00050044();

void FUN_00051464(int param_1)
{
  FUN_00050044((int)&DAT_00311170,*(u32 *)(param_1 + 4),0);
}
