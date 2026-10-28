/* HSTMATCH module=hstp_trans_main.prx start=0x001cf7b0 end=0x001cf7d0 symbol=FUN_001cf7b0 lang=c99 */
/* Clone of src/eboot/FUN_001c159c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001cf7b0(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8)
{
  *(u32 *)(param_1 + 0x38) = param_2;
  *(u32 *)(param_1 + 0x3c) = param_3;
  *(u32 *)(param_1 + 0x24) = param_4;
  *(u32 *)(param_1 + 0x28) = param_5;
  *(u32 *)(param_1 + 0x2c) = param_6;
  *(u32 *)(param_1 + 0x30) = param_7;
  *(u32 *)(param_1 + 0x34) = param_8;
}
