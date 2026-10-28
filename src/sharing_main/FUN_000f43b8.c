/* HSTMATCH module=hstp_trans_main.prx start=0x000f43b8 end=0x000f4414 symbol=FUN_000f43b8 lang=c99 */
/* Clone of src/eboot/FUN_000eecf0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e19f0;
extern void FUN_00105470();
extern void FUN_00108a2c();

void FUN_000f43b8(int param_1)
{
  u8 uVar1;
  
  if (*(u8 *)(param_1 + 0x54) == '\0') {
    uVar1 = *(u8 *)(DAT_003e19f0 + 0x4c);
    FUN_00105470(*(u32 *)(param_1 + 0x5c),uVar1);
    FUN_00105470(*(u32 *)(param_1 + 0x60),uVar1);
    FUN_00108a2c(param_1);
  }
}
