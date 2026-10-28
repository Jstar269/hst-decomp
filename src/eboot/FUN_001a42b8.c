/* HSTMATCH module=EBOOT.BIN start=0x001a42b8 end=0x001a4334 symbol=FUN_001a42b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted dispatch condition and widened comparison flag to int; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0016baa0();
extern int FUN_001a4334();

void FUN_001a42b8(int param_1,int param_2)
{
  int bVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = **(int **)(*(int *)(param_1 + 900) + *(int *)(param_1 + 0x300) * 4);
    bVar1 = iVar2 == -1;
    if (bVar1) {
      iVar2 = FUN_001a4334();
    }
    FUN_0016baa0(iVar2,bVar1);
  }
  else {
    *(u32 *)(param_1 + 0x2fc) = *(u32 *)(param_1 + 0x308);
    *(u32 *)(param_1 + 0x300) = *(u32 *)(param_1 + 0x30c);
    *(u32 *)(param_1 + 0x304) = *(u32 *)(param_1 + 0x310);
  }
}
