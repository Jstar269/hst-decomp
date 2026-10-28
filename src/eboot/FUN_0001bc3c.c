/* HSTMATCH module=EBOOT.BIN start=0x0001bc3c end=0x0001bc6c symbol=FUN_0001bc3c lang=c99 */
/* Clone of src/sharing_main/FUN_0001b6e0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0030ebd4;
extern void FUN_0001b944();
extern void FUN_002b7978();

u32 FUN_0001bc3c(void)
{
  FUN_0001b944();
  DAT_0030ebd4 = 0;
  FUN_002b7978(0);
  return 0;
}
