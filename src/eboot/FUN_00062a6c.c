/* HSTMATCH module=EBOOT.BIN start=0x00062a6c end=0x00062a9c symbol=FUN_00062a6c lang=c99 */
/* Clone of src/sharing_main/FUN_00063930.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000775d0();

bool FUN_00062a6c(int param_1)
{
  bool bVar1;
  u32 uVar2;
  
  if (param_1 < 0) {
    bVar1 = false;
  }
  else {
    uVar2 = FUN_000775d0();
    bVar1 = (uVar2 & 3) != 0;
  }
  return bVar1;
}
