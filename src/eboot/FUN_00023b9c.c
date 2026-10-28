/* HSTMATCH module=EBOOT.BIN start=0x00023b9c end=0x00023bb8 symbol=FUN_00023b9c lang=c99 */
/* Clone of src/sharing_main/FUN_00023bc4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00023b9c(int param_1,u32 param_2,u32 param_3,u32 param_4)
{
  if (param_1 != 0) {
    *(u32 *)(param_1 + 0x6c) = param_4;
    *(u32 *)(param_1 + 100) = param_2;
    *(u32 *)(param_1 + 0x68) = param_3;
  }
}
