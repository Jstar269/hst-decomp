/* HSTMATCH module=EBOOT.BIN start=0x000f5dcc end=0x000f5e20 symbol=FUN_000f5dcc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000f5dcc(int param_1)
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
