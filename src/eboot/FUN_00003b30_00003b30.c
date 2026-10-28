/* HSTMATCH module=EBOOT.BIN start=0x00003b30 end=0x00003b5c symbol=FUN_00003b30 lang=c99 */
/* Clone of src/sharing_main/FUN_00003b30.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00003064();
extern int FUN_00003b5c();

int FUN_00003b30(void)
{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = FUN_00003064();
  uVar2 = FUN_00003b5c(uVar1);
  return (uVar2 >> 1) - 1;
}
