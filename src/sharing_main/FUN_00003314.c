/* HSTMATCH module=hstp_trans_main.prx start=0x00003314 end=0x00003370 symbol=FUN_00003314 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00003100();
extern u32 FUN_00003c74();
extern int FUN_000041d0();

void FUN_00003314(u32 param_1,u32 param_2)
{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = FUN_00003100(param_1);
  uVar2 = FUN_000041d0(param_2);
  FUN_00003c74(param_1,0,uVar1,param_2,uVar2);
}
