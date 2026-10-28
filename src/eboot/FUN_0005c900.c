/* HSTMATCH module=EBOOT.BIN start=0x0005c900 end=0x0005c954 symbol=FUN_0005c900 lang=c99 */
/* Clone of src/sharing_main/FUN_0005d68c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000009e4();
extern int FUN_00000a90();

void FUN_0005c900(int param_1,int param_2)
{
  u32 uVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_000009e4(*(int *)(param_1 + 0x1c));
    *(u32 *)(param_1 + 0x1c) = 0;
  }
  *(int *)(param_1 + 0x18) = param_2;
  if (0 < param_2) {
    uVar1 = FUN_00000a90(param_2 << 5);
    *(u32 *)(param_1 + 0x1c) = uVar1;
  }
}
