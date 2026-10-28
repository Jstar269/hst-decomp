/* HSTMATCH module=EBOOT.BIN start=0x000030d0 end=0x000030f8 symbol=FUN_000030d0 lang=c99 */
/* Clone of src/sharing_main/FUN_000030d0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000030a8();

bool FUN_000030d0(void)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_000030a8();
  return (*puVar1 & 1) != 0;
}
