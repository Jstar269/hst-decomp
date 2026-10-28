/* HSTMATCH module=EBOOT.BIN start=0x000031d0 end=0x000031f0 symbol=FUN_000031d0 lang=c99 */
/* Clone of src/sharing_main/FUN_000030b0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00003004();

int FUN_000031d0(void)
{
  int iVar1;
  
  iVar1 = FUN_00003004();
  return iVar1 + 1;
}
