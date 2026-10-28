/* HSTMATCH module=EBOOT.BIN start=0x001ea8f0 end=0x001ea930 symbol=FUN_001ea8f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p2), refined by hstperm.py random mutation from try/gen-p64a/v0/FUN_001ea8f0.c; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001ea8f0(int *param_1)
{
  int iVar1;
  int iVar3;
  int iVar2;
  
  iVar1 = *param_1;
  iVar3 = 0;
  iVar2 = iVar1;
  do {
    *(u32 *)(iVar2 + 1000) = 0xffffffff;
    *(u32 *)(iVar2 + 0x3ec) = 0xffffffff;
    *(u32 *)(iVar2 + 0x3f0) = 0xffffffff;
    *(u32 *)(iVar2 + 0x3f4) = 0xffffffff;
    *(u32 *)(iVar2 + 0x3f8) = 0xffffffff;
    iVar3 = iVar3 + 1;
    *(u32 *)(iVar2 + 0x3fc) = 0xffffffff;
    iVar2 = iVar2 + 0x18;
  } while (iVar3 < 2);
  *(u8 *)(iVar1 + 0x418) = 0;
}
