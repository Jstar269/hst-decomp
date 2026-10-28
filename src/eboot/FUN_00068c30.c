/* HSTMATCH module=EBOOT.BIN start=0x00068c30 end=0x00068c40 symbol=FUN_00068c30 lang=c99 */
/* Clone of src/sharing_main/FUN_0006a084.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00068b80();

void FUN_00068c30(u32 *param_1,u32 param_2,u32 param_3)
{
  *param_1 = param_2;
  FUN_00068b80(param_1 + 1,param_3);
}
