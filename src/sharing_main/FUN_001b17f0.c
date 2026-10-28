/* HSTMATCH module=hstp_trans_main.prx start=0x001b17f0 end=0x001b1844 symbol=FUN_001b17f0 lang=c99 */
/* Clone of src/eboot/FUN_001a4224.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00177b5c();

void FUN_001b17f0(int param_1)
{
  FUN_00177b5c(**(u32 **)(*(int *)(param_1 + 0x378) + *(int *)(param_1 + 0x2c4) * 4));
  *(u32 *)(param_1 + 0x2cc) = *(u32 *)(param_1 + 0x2c0);
  *(u32 *)(param_1 + 0x2d0) = *(u32 *)(param_1 + 0x2c4);
  *(u32 *)(param_1 + 0x2d4) = *(u32 *)(param_1 + 0x2c8);
}
