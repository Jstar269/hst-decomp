/* HSTMATCH module=EBOOT.BIN start=0x00003190 end=0x000031b0 symbol=FUN_00003190 lang=c99 */
/* Clone of src/sharing_main/FUN_00003148.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00003004();

int FUN_00003190(void)
{
  int iVar1;
  
  iVar1 = FUN_00003004();
  return iVar1 + 4;
}
