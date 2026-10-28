/* HSTMATCH module=hstp_trans_main.prx start=0x0011fe30 end=0x0011fe78 symbol=FUN_0011fe30 lang=c99 */
/* Clone of src/eboot/FUN_00115040.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0011eab8();

void FUN_0011fe30(int param_1,u32 param_2)
{
  *(u8 *)(*(int *)(param_1 + 0x54) + 0x90a) = 1;
  *(u32 *)(param_1 + 0x80) = param_2;
  FUN_0011eab8(param_1,5);
  *(u32 *)(param_1 + 0x80) = param_2;
}
