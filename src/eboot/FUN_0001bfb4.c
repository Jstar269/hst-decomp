/* HSTMATCH module=EBOOT.BIN start=0x0001bfb4 end=0x0001bfc0 symbol=FUN_0001bfb4 lang=c99 */
/* Clone of src/sharing_main/FUN_0001bb2c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0001bfb4(int param_1,u32 param_2,u32 param_3)
{
  *(u32 *)(param_1 + 0x18) = param_2;
  *(u32 *)(param_1 + 0x1c) = param_3;
}
