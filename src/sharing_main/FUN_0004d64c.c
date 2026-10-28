/* HSTMATCH module=hstp_trans_main.prx start=0x0004d64c end=0x0004d698 symbol=FUN_0004d64c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc260;
extern u32 * FUN_00022598();
extern u32 * FUN_00022634();

void FUN_0004d64c(u32 param_1,u32 param_2)
{
  u8 auStack_40 [64];
  
  FUN_00022634(auStack_40,&DAT_002cc260);
  FUN_00022598(param_1,param_2,auStack_40);
}
