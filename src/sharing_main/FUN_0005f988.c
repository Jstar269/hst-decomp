/* HSTMATCH module=hstp_trans_main.prx start=0x0005f988 end=0x0005fa04 symbol=FUN_0005f988 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00060020();
extern void FUN_0006037c();

void FUN_0005f988(int param_1)
{
  *(u32 *)(param_1 + 0xa0) = 0xffffffff;
  *(u32 *)(param_1 + 0xa4) = 0;
  *(u8 *)(param_1 + 0xc0) = 0;
  *(u32 *)(param_1 + 0xc4) = 0x3f800000;
  *(u32 *)(param_1 + 200) = 0;
  *(u32 *)(param_1 + 0xcc) = 0;
  *(u32 *)(param_1 + 0xd0) = 0;
  if (*(u32 *)(param_1 + 0xb0) < 0x40) {
    FUN_0006037c(param_1 + 0xa8,0x40);
  }
  if ((u32)(*(int *)(param_1 + 0xbc) << 5) < 0x40) {
    FUN_00060020(param_1 + 0xb4,0x40);
  }
}
