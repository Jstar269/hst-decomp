/* HSTMATCH module=EBOOT.BIN start=0x000ff3f0 end=0x000ff414 symbol=FUN_000ff3f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_000ff3f0.c; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_000ff3f0(int param_1,u32 param_2)
{
  u32 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 >= 0x14) {
    uVar1 = *(u32 *)(0xc + param_1) ^ 0x8729382e;
  }
  return uVar1;
}
