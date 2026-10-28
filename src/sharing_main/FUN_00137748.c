/* HSTMATCH module=hstp_trans_main.prx start=0x00137748 end=0x001377d0 symbol=FUN_00137748 lang=c99 */
/* Clone of src/eboot/FUN_0012c2dc.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d10e0;
extern void FUN_00137eb8();

int FUN_00137748(int param_1)
{
  *(u8 **)(param_1 + 0x40) = &DAT_002d10e0;
  *(u32 *)(param_1 + 0x70) = 0;
  *(u32 *)(param_1 + 0x74) = 0;
  *(u32 *)(param_1 + 0x78) = 0;
  *(u32 *)(param_1 + 0x84) = 0;
  *(u32 *)(param_1 + 0x88) = 0;
  *(u32 *)(param_1 + 0x8c) = 0;
  if (*(u32 *)(param_1 + 0x78) < 10) {
    FUN_00137eb8(param_1 + 0x70,10);
  }
  if (*(u32 *)(param_1 + 0x8c) < 10) {
    FUN_00137eb8(param_1 + 0x84,10);
  }
  *(u32 *)(param_1 + 0x90) = 0x3f800000;
  *(u8 *)(param_1 + 0x94) = 0;
  return param_1;
}
