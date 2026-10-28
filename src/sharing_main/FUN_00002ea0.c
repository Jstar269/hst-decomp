/* HSTMATCH module=hstp_trans_main.prx start=0x00002ea0 end=0x00002ee0 symbol=FUN_00002ea0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00002e7c();
extern u32 FUN_00002ee0();
extern u32 FUN_00002ee8();

void FUN_00002ea0(int param_1)
{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = FUN_00002ee8(param_1 + 0xc);
  puVar2 = (u32 *)FUN_00002ee0(param_1 + 0xc);
  FUN_00002e7c(uVar1,*puVar2);
}
