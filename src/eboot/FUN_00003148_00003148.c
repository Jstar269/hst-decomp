/* HSTMATCH module=EBOOT.BIN start=0x00003148 end=0x00003168 symbol=FUN_00003148 lang=c99 */
/* Clone of src/sharing_main/FUN_00003148.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000030a8();

int FUN_00003148(void)
{
  int iVar1;
  
  iVar1 = FUN_000030a8();
  return iVar1 + 4;
}
