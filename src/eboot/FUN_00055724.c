/* HSTMATCH module=EBOOT.BIN start=0x00055724 end=0x00055768 symbol=FUN_00055724 lang=c99 */
/* Clone of src/sharing_main/FUN_000562d0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00054358();
extern void FUN_000555b4();

void FUN_00055724(u32 param_1,int param_2)
{
  u32 uVar1;
  u8 auStack_40 [64];
  
  uVar1 = *(u32 *)(param_2 + 0x8c);
  FUN_000555b4(auStack_40);
  FUN_00054358(param_1,uVar1,auStack_40);
}
