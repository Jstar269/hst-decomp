/* HSTMATCH module=hstp_trans_main.prx start=0x000fb4c0 end=0x000fb514 symbol=FUN_000fb4c0 lang=c99 */
/* Clone of src/eboot/FUN_000f5dcc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000fb4c0(int param_1)
{
  u32 uVar1;
  
  uVar1 = 0;
  do {
    *(u8 *)(param_1 + 0xa0) = 0;
    *(u32 *)(param_1 + 0xa4) = 0x10;
    *(u32 *)(param_1 + 0xa8) = 0;
    *(u32 *)(param_1 + 0xac) = 0xffffffff;
    *(u32 *)(param_1 + 0xb0) = 0;
    *(u32 *)(param_1 + 0xb4) = 0;
    *(u32 *)(param_1 + 0xc0) = 0;
    *(u32 *)(param_1 + 0xc4) = 0;
    *(u32 *)(param_1 + 200) = 0;
    *(u32 *)(param_1 + 0xcc) = 0x3f800000;
    uVar1 = uVar1 + 1;
    *(u32 *)(param_1 + 0xd0) = 0;
    param_1 = param_1 + 0x40;
  } while (uVar1 < 0x10);
}
