/* HSTMATCH module=EBOOT.BIN start=0x0011d050 end=0x0011d0ac symbol=FUN_0011d050 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0011d520();

void FUN_0011d050(int param_1,int param_2)
{
  u32 uVar1;
  
  if (param_1 != param_2) {
    FUN_0011d520();
    uVar1 = *(u32 *)(param_1 + 0x10);
    *(u32 *)(param_1 + 0x10) = *(u32 *)(param_2 + 0x10);
    *(u32 *)(param_2 + 0x10) = uVar1;
    uVar1 = *(u32 *)(param_1 + 0x14);
    *(u32 *)(param_1 + 0x14) = *(u32 *)(param_2 + 0x14);
    *(u32 *)(param_2 + 0x14) = uVar1;
  }
}
