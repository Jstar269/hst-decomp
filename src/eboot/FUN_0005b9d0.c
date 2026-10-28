/* HSTMATCH module=EBOOT.BIN start=0x0005b9d0 end=0x0005ba00 symbol=FUN_0005b9d0 lang=c99 */
/* Clone of src/sharing_main/FUN_0005c658.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0005ba78();

int FUN_0005b9d0(int param_1)
{
  *(u32 *)(param_1 + 0x1c) = 0;
  *(u32 *)(param_1 + 0x24) = 0;
  FUN_0005ba78();
  return param_1;
}
