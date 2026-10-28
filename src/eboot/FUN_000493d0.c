/* HSTMATCH module=EBOOT.BIN start=0x000493d0 end=0x000493fc symbol=FUN_000493d0 lang=c99 */
/* Clone of src/sharing_main/FUN_00049280.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000493d0(int param_1)
{
  *(u32 *)(param_1 + 8) = 0xffffffff;
  *(u32 *)(param_1 + 0xc) = 0xffffffff;
  *(u32 *)(param_1 + 0x10) = 0xffffffff;
  *(u32 *)(param_1 + 0x14) = 0xffffffff;
  *(u32 *)(param_1 + 0x18) = 0xffffffff;
  *(u32 *)(param_1 + 0x1c) = 0xffffffff;
  *(u32 *)(param_1 + 0x20) = 0x477ffe00;
}
