/* HSTMATCH module=EBOOT.BIN start=0x00003c50 end=0x00003c74 symbol=FUN_00003c50 lang=c99 */
/* Clone of src/sharing_main/FUN_00003c50.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000030a8();

u32 FUN_00003c50(void)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_000030a8();
  return *puVar1 >> 1;
}
