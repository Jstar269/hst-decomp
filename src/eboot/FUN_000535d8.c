/* HSTMATCH module=EBOOT.BIN start=0x000535d8 end=0x00053618 symbol=FUN_000535d8 lang=c99 */
/* Clone of src/sharing_main/FUN_00054098.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000537a0();

int FUN_000535d8(int param_1)
{
  *(u32 *)(param_1 + 0x18) = 0;
  *(u32 *)(param_1 + 0x1c) = 0;
  *(u32 *)(param_1 + 0x20) = 0;
  *(u32 *)(param_1 + 0x24) = 0;
  *(u32 *)(param_1 + 0x28) = 0;
  *(u32 *)(param_1 + 0x2c) = 0;
  FUN_000537a0();
  return param_1;
}
