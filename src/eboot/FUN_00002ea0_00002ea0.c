/* HSTMATCH module=EBOOT.BIN start=0x00002ea0 end=0x00002ee0 symbol=FUN_00002ea0 lang=c99 */
/* Clone of src/sharing_main/FUN_00002ea0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00002e7c();
extern u32 FUN_00002ee0();
extern u32 FUN_00002ee8();

void FUN_00002ea0(int param_1)
{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = FUN_00002ee8(param_1 + 0xc);
  puVar2 = (u32 *)FUN_00002ee0(param_1 + 0xc);
  FUN_00002e7c(uVar1,*puVar2);
}
