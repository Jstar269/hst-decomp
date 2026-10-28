/* HSTMATCH module=EBOOT.BIN start=0x000ff3cc end=0x000ff3f0 symbol=FUN_000ff3cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_000ff3cc.c; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_000ff3cc(int param_1,u32 param_2)
{
  int uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 >= 0x14) {
    uVar1 = *(u32 *)(8 + param_1) ^ 0x3456ff33;
  }
  return uVar1;
}
