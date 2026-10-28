/* HSTMATCH module=hstp_trans_main.prx start=0x001d19d8 end=0x001d1a64 symbol=FUN_001d19d8 lang=c99 */
/* Clone of src/eboot/FUN_001c364c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea914;
extern void FUN_001699cc();
extern void FUN_0019cdc8();
extern void FUN_001d8ec4();
extern void FUN_001dbab4();
extern void FUN_001dbf68();

void FUN_001d19d8(int param_1)
{
  if (*(int *)(param_1 + 8) == 0x1e) {
    if (*(int *)(param_1 + 0xf8) == 1) {
      FUN_001699cc();
    }
    else {
      FUN_001d8ec4(*(u32 *)(param_1 + 0x18));
      *(u32 *)(param_1 + 0xe8) = 1;
      *(u8 *)(param_1 + 0xf0) = 0;
      FUN_0019cdc8(DAT_003ea914,3);
      FUN_001dbf68(param_1,8,1);
      FUN_001dbab4(*(u32 *)(param_1 + 0x18));
    }
  }
}
