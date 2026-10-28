/* HSTMATCH module=EBOOT.BIN start=0x0018a950 end=0x0018a960 symbol=FUN_0018a950 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010d4a8();

void FUN_0018a950(int param_1,u32 param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x78);
  *(u32 *)(iVar1 + 0xf8) = param_2;
  *(u32 *)(iVar1 + 0x138) = 0;
  FUN_0010d4a8(iVar1);
}
