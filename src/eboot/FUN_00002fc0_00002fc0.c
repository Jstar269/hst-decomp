/* HSTMATCH module=EBOOT.BIN start=0x00002fc0 end=0x00002fe8 symbol=FUN_00002fc0 lang=c99 */
/* Clone of src/sharing_main/FUN_00002fc0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00002fe8();

void FUN_00002fc0(void)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_00002fe8();
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
}
