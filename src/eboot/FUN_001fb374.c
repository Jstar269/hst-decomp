/* HSTMATCH module=EBOOT.BIN start=0x001fb374 end=0x001fb3bc symbol=FUN_001fb374 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001fb374(int param_1)
{
  int iVar1;
  
  *(u32 *)(param_1 + 0x1030) = 0;
  *(u32 *)(param_1 + 0x1034) = 0;
  iVar1 = 0;
  do {
    *(u32 *)(param_1 + 0xf90) = 0xffffffff;
    *(u32 *)(param_1 + 0xf94) = 0xffffffff;
    *(u32 *)(param_1 + 0xf98) = 0xffffffff;
    *(u32 *)(param_1 + 0xf9c) = 0xffffffff;
    *(u32 *)(param_1 + 4000) = 0xffffffff;
    *(u32 *)(param_1 + 0xfa4) = 0xffffffff;
    *(u32 *)(param_1 + 0xfa8) = 0xffffffff;
    iVar1 = iVar1 + 8;
    *(u32 *)(param_1 + 0xfac) = 0xffffffff;
    param_1 = param_1 + 0x20;
  } while (iVar1 < 0x28);
}
