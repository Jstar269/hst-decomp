/* HSTMATCH module=hstp_trans_main.prx start=0x00233114 end=0x00233178 symbol=FUN_00233114 lang=c99 */
/* Clone of src/eboot/FUN_00223ba0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00233324();

void FUN_00233114(int param_1)
{
  FUN_00233324();
  *(u32 *)(param_1 + 0x78) = 0xffffffff;
  *(u32 *)(param_1 + 0x7c) = 0;
  *(u32 *)(param_1 + 0x84) = 0;
  *(u32 *)(param_1 + 0x8c) = 0;
  *(u32 *)(param_1 + 0x94) = 0;
  *(u32 *)(param_1 + 0x9c) = 0;
  *(u8 *)(param_1 + 0xa4) = 0;
  *(u8 *)(param_1 + 0xa6) = 0;
  *(u32 *)(param_1 + 0x80) = 0;
  *(u32 *)(param_1 + 0x88) = 0;
  *(u32 *)(param_1 + 0x90) = 0;
  *(u32 *)(param_1 + 0x98) = 0;
  *(u32 *)(param_1 + 0xa0) = 0;
  *(u8 *)(param_1 + 0xa5) = 0;
  *(u8 *)(param_1 + 0xa7) = 0;
}
