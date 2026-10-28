/* HSTMATCH module=hstp_trans_main.prx start=0x00057c2c end=0x00057c88 symbol=FUN_00057c2c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed the initialization helper receiver, retained its result through the nonnull guard, and used one shared field store; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 * FUN_00056d24();
extern void FUN_00057ce0();
extern void FUN_00057fa0(int);

void FUN_00057c2c(int param_1,u32 param_2)
{
  int iVar1;
  u32 uVar2;
  
  FUN_00057fa0(param_1);
  iVar1 = FUN_00000bcc(0x10);
  if (iVar1 != 0) {
    iVar1 = (int)FUN_00056d24(iVar1,param_2,0);
  }
  *(u32 *)(param_1 + 0x168) = iVar1;
  FUN_00057ce0(param_1);
}
