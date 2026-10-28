/* HSTMATCH module=EBOOT.BIN start=0x000c825c end=0x000c82c8 symbol=FUN_000c825c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_000008d8();
extern int FUN_00000a90();
extern void FUN_00056b98();
extern void FUN_00056cb0();

void FUN_000c825c(int param_1)
{
  u32 uVar1;
  
  if (*(int *)(param_1 + 0x1d0) == 0) {
    uVar1 = FUN_00000a90(0x6d0);
    uVar1 = (unsigned int)(FUN_000008d8(uVar1,FUN_00056b98,FUN_00056cb0,0x1b0,4));
    *(u32 *)(param_1 + 0x1d0) = uVar1;
  }
  if (*(int *)(param_1 + 0x1d4) == 0) {
    uVar1 = FUN_00000a90(4);
    *(u32 *)(param_1 + 0x1d4) = uVar1;
  }
}
