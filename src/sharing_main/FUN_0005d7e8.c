/* HSTMATCH module=hstp_trans_main.prx start=0x0005d7e8 end=0x0005d83c symbol=FUN_0005d7e8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000009e4();
extern int FUN_00000a90();

void FUN_0005d7e8(int param_1,int param_2)
{
  u32 uVar1;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    FUN_000009e4(*(int *)(param_1 + 0x24));
    *(u32 *)(param_1 + 0x24) = 0;
  }
  *(int *)(param_1 + 0x20) = param_2;
  if (0 < param_2) {
    uVar1 = FUN_00000a90(param_2 << 6);
    *(u32 *)(param_1 + 0x24) = uVar1;
  }
}
