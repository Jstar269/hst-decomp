/* HSTMATCH module=EBOOT.BIN start=0x000fa98c end=0x000fa9d4 symbol=FUN_000fa98c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p2), refined by hstperm.py random mutation from try/gen-p128a/v0/FUN_000fa98c.c; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000fa98c(int param_1)
{
  u32 uVar3;
  int iVar2;
  int iVar1;
  
  uVar3 = 0;
  iVar2 = param_1;
  do {
    iVar1 = *(int *)(param_1 + 0x9c);
    if (iVar1 != 0) {
      *(u32 *)(iVar2 + 200) = 0;
      *(u32 *)(iVar1 + 0x60) = 0;
      *(u32 *)(iVar2 + 0xcc) = 0;
      *(u32 *)(iVar1 + 100) = 0;
      *(u32 *)(iVar2 + 0xd0) = 0;
      *(u32 *)(iVar1 + 0x78) = 0;
    }
    uVar3 = uVar3 + 1;
    param_1 += 4;
    iVar2 = iVar2 + 0xc;
  } while (uVar3 < 0xb);
}
