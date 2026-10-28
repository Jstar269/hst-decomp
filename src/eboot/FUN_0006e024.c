/* HSTMATCH module=EBOOT.BIN start=0x0006e024 end=0x0006e094 symbol=FUN_0006e024 lang=c99 */
/* Clone of src/sharing_main/FUN_0006f6ec.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_00331c2c;
extern void FUN_00000a00();
extern void FUN_0006e93c();

int FUN_0006e024(int param_1,short param_2)
{
  if (param_1 != 0) {
    if ((DAT_00331c2c != 0) && (*(int *)(param_1 + 4) != 0)) {
      FUN_0006e93c(DAT_00331c2c + 0xc,*(int *)((int)param_1 + 4));
      *(u32 *)(param_1 + 4) = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
