/* HSTMATCH module=EBOOT.BIN start=0x00002bfc end=0x00002c34 symbol=FUN_00002bfc lang=c99 */
/* Clone of src/sharing_main/FUN_00002bfc.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00002c34();

u32 FUN_00002bfc(u32 param_1)
{
  u32 *puVar1;
  u32 uVar2;
  
  puVar1 = (u32 *)FUN_00002c34();
  uVar2 = *puVar1;
  puVar1 = (u32 *)FUN_00002c34(param_1);
  *puVar1 = 0;
  return uVar2;
}
