/* HSTMATCH module=hstp_trans_main.prx start=0x0000430c end=0x0000435c symbol=FUN_0000430c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00003100();
extern void FUN_00003778();
extern u32 FUN_00003c74();

void FUN_0000430c(u32 param_1,u32 param_2)
{
  u32 uVar1;
  u32 local_4;
  u32 local_8;
  
  FUN_00003778(param_2,&local_4,&local_8);
  uVar1 = FUN_00003100(param_1);
  FUN_00003c74(param_1,0,uVar1,local_4,local_8);
}
