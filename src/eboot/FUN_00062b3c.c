/* HSTMATCH module=EBOOT.BIN start=0x00062b3c end=0x00062b64 symbol=FUN_00062b3c lang=c99 */
/* Clone of src/sharing_main/FUN_00063a00.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000784d4();

u32 FUN_00062b3c(int param_1)
{
  u32 uVar1;
  
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_000784d4();
  }
  return uVar1;
}
