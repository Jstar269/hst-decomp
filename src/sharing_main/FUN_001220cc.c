/* HSTMATCH module=hstp_trans_main.prx start=0x001220cc end=0x001220f8 symbol=FUN_001220cc lang=c99 */
/* Clone of src/eboot/FUN_00117128.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001220cc(int param_1)
{
  *(u8 *)(param_1 + 0x4c) = 0;
  *(u32 *)(param_1 + 0x50) = 0;
  *(u8 *)(param_1 + 0x54) = 0;
  *(u32 *)(param_1 + 0x58) = 0;
  *(u32 *)(param_1 + 0x5c) = 0xffffffff;
  *(u32 *)(param_1 + 0x60) = 0xffffffff;
  *(u32 *)(param_1 + 100) = 0xffffffff;
  *(u32 *)(param_1 + 0x6c) = 0xffffffff;
  *(u8 *)(param_1 + 0x40) = 0;
}
