/* HSTMATCH module=EBOOT.BIN start=0x00056fd8 end=0x00057034 symbol=FUN_00056fd8 lang=c99 */
/* Clone of src/sharing_main/FUN_00057c2c.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed the initialization helper receiver, retained its result through the nonnull guard, and used one shared field store; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 * FUN_00056110();
extern void FUN_0005708c();
extern void FUN_0005734c(int);

void FUN_00056fd8(int param_1,u32 param_2)
{
  int iVar1;
  u32 uVar2;
  
  FUN_0005734c(param_1);
  iVar1 = FUN_00000bcc(0x10);
  if (iVar1 != 0) {
    iVar1 = (int)FUN_00056110(iVar1,param_2,0);
  }
  *(u32 *)(param_1 + 0x168) = iVar1;
  FUN_0005708c(param_1);
}
