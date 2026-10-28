/* HSTMATCH module=EBOOT.BIN start=0x0006a208 end=0x0006a254 symbol=FUN_0006a208 lang=c99 */
/* Clone of src/sharing_main/FUN_0006b76c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00331c28;
extern void FUN_0006b200();

u32 FUN_0006a208(u32 param_1)
{
  u32 uVar1;
  int local_4;
  u32 local_8;
  
  local_8 = param_1;
  FUN_0006b200(&local_4,DAT_00331c28 + 0x1c,&local_8);
  if (local_4 == DAT_00331c28 + 0x20) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(u32 *)(local_4 + 0x10);
  }
  return uVar1;
}
