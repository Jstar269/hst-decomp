/* HSTMATCH module=EBOOT.BIN start=0x001b3148 end=0x001b31ac symbol=FUN_001b3148 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001b0ef8();

void FUN_001b3148(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = param_2 * 8;
  FUN_001b0ef8(iVar1,param_2 * 2 + 0x16a,0,0,0);
  *(u32 *)(iVar1 + 0x788) = *(u32 *)(iVar2 + iVar1 + 0x5a8);
  *(int *)(iVar1 + 0x7d8) = param_2;
  *(u8 *)(iVar1 + 0x7dc) = 1;
}
