/* HSTMATCH module=EBOOT.BIN start=0x0005ca5c end=0x0005cab0 symbol=FUN_0005ca5c lang=c99 */
/* Clone of src/sharing_main/FUN_0005d7e8.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000009e4();
extern int FUN_00000a90();

void FUN_0005ca5c(int param_1,int param_2)
{
  u32 uVar1;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    FUN_000009e4(*(int *)(param_1 + 0x24));
    *(u32 *)(param_1 + 0x24) = 0;
  }
  *(int *)(param_1 + 0x20) = param_2;
  if (0 < param_2) {
    uVar1 = FUN_00000a90(param_2 << 6);
    *(u32 *)(param_1 + 0x24) = uVar1;
  }
}
