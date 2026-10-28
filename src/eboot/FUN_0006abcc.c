/* HSTMATCH module=EBOOT.BIN start=0x0006abcc end=0x0006ac10 symbol=FUN_0006abcc lang=c99 */
/* Clone of src/sharing_main/FUN_0006c1b4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000006e8();
extern void FUN_000009e4();
extern void FUN_00056cb0();

void FUN_0006abcc(u32 *param_1)
{
  FUN_000009e4(param_1[2]);
  param_1[2] = 0;
  FUN_000006e8(param_1[1],FUN_00056cb0);
  param_1[1] = 0;
  *param_1 = 0;
}
