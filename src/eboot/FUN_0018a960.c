/* HSTMATCH module=EBOOT.BIN start=0x0018a960 end=0x0018a9fc symbol=FUN_0018a960 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2), refined by hstperm.py tag p4 random mutation from try/gen-a2/v0/FUN_0018a960.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();
extern void FUN_0010d4a8();
extern void FUN_0018a9fc();

void FUN_0018a960(int param_1,u32 param_2,int param_3)
{
  int iVar3;
  int iVar2;
  int iVar1;
  
  if (param_3 != 0) {
    FUN_0018a9fc(param_1);
  }
  *(u32 *)(param_1 + 0x98) = param_2;
  iVar3 = 0;
  iVar2 = param_1;
  do {
    FUN_000114c0((u32 *)(iVar2 + 0x9c),0,0x400);
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0x400;
  } while (3 > iVar3);
  iVar3 = 0;
  iVar2 = param_1;
  do {
    iVar1 = *(int *)(param_1 + 0x7c);
    *(int *)(iVar1 + 0xf8) = iVar2 + 0x9c;
    *(u32 *)(iVar1 + 0x138) = 0;
    FUN_0010d4a8(iVar1);
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 4;
    iVar2 = iVar2 + 0x400;
  } while (iVar3 < 2);
}
