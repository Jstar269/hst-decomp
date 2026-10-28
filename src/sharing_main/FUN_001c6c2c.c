/* HSTMATCH module=hstp_trans_main.prx start=0x001c6c2c end=0x001c6c80 symbol=FUN_001c6c2c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern char DAT_0039157f[];
extern void FUN_00000020();
extern void FUN_00000028();
extern void FUN_001c1d9c();

void FUN_001c6c2c(u32 param_1,u32 param_2,u32 param_3)
{
  FUN_00000020(DAT_0039157f + 1);
  FUN_001c1d9c((int)&DAT_003eaad8,param_2,param_3);
  FUN_00000028();
}
