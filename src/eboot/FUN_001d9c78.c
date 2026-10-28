/* HSTMATCH module=EBOOT.BIN start=0x001d9c78 end=0x001d9cc4 symbol=FUN_001d9c78 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001d0624();
extern void FUN_001d57f0();

void FUN_001d9c78(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  *(u32 *)(iVar1 + 0xd4) = 3;
  *(u32 *)(iVar1 + 0x520) = 4;
  FUN_001d0624(iVar1 + 0x1110,8);
  FUN_001d57f0(iVar1,5,0);
}
