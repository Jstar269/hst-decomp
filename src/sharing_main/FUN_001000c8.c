/* HSTMATCH module=hstp_trans_main.prx start=0x001000c8 end=0x00100110 symbol=FUN_001000c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p2), refined by hstperm.py random mutation from try/gen-sh128a/v0/FUN_001000c8.c; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001000c8(int param_1)
{
  int iVar1;
  u32 uVar3;
  int iVar2;
  
  uVar3 = 0;
  iVar2 = param_1;
  do {
    iVar1 = *(int *)(param_1 + 0x9c);
    if (0 != iVar1) {
      *(u32 *)(iVar2 + 200) = 0;
      *(u32 *)(iVar1 + 0x60) = 0;
      *(u32 *)(iVar2 + 0xcc) = 0;
      *(u32 *)(iVar1 + 100) = 0;
      *(u32 *)(iVar2 + 0xd0) = 0;
      *(u32 *)(iVar1 + 0x78) = 0;
    }
    uVar3 = uVar3 + 1;
    param_1 = param_1 + 4;
    iVar2 = iVar2 + 0xc;
  } while (uVar3 < 0xb);
}
