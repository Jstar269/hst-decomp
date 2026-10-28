/* HSTMATCH module=EBOOT.BIN start=0x00055df8 end=0x00055e48 symbol=FUN_00055df8 lang=c99 */
/* Clone of src/sharing_main/FUN_000569a4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00055e98();
extern u32 FUN_00055eac();

u32 FUN_00055df8(u32 param_1,u32 param_2,u32 param_3)
{
  FUN_00055e98(param_1);
  FUN_00055eac(param_1,param_2,param_3);
  return param_1;
}
