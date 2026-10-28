/* HSTMATCH module=EBOOT.BIN start=0x0001f1fc end=0x0001f20c symbol=FUN_0001f1fc lang=c99 */
/* Clone of src/sharing_main/FUN_0001ef14.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0001f1fc(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x24) = param_2;
  *(u8 *)(param_1 + 0x2c) = param_2;
  *(u8 *)(param_1 + 0x34) = param_2;
}
