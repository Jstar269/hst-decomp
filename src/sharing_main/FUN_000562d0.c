/* HSTMATCH module=hstp_trans_main.prx start=0x000562d0 end=0x00056314 symbol=FUN_000562d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00054ea4();
extern void FUN_00056160();

void FUN_000562d0(u32 param_1,int param_2)
{
  u32 uVar1;
  u8 auStack_40 [64];
  
  uVar1 = *(u32 *)(param_2 + 0x8c);
  FUN_00056160(auStack_40);
  FUN_00054ea4(param_1,uVar1,auStack_40);
}
