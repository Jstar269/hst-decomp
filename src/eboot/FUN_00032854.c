/* HSTMATCH module=EBOOT.BIN start=0x00032854 end=0x00032860 symbol=FUN_00032854 lang=c99 */
/* Clone of src/sharing_main/FUN_0003287c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00032748();

void FUN_00032854(int param_1)
{
  FUN_00032748(param_1,*(u32 *)(param_1 + 4),param_1 + 0x18);
}
