/* HSTMATCH module=EBOOT.BIN start=0x000c50cc end=0x000c5100 symbol=FUN_000c50cc lang=c99 */
/* Clone of src/sharing_main/FUN_000c8b50.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338ac4;
extern u32 FUN_000bae04();
extern void FUN_002862a8();

void FUN_000c50cc(int param_1)
{
  FUN_002862a8(*(u32 *)(param_1 + 0x784));
  if (DAT_00338ac4 != 0) {
    FUN_000bae04(DAT_00338ac4);
  }
}
