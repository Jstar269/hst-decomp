/* HSTMATCH module=EBOOT.BIN start=0x001a444c end=0x001a44a4 symbol=FUN_001a444c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: FUN_0016baa0 takes an int first parameter (no seh, the short cast dropped); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0016b534(void);
extern void FUN_0016baa0(int param_1,u8 param_2);

void FUN_001a444c(int param_1)
{
  bool bVar1;
  int iVar2;
  
  iVar2 = **(int **)(*(int *)(param_1 + 900) + *(int *)(param_1 + 0x300) * 4);
  bVar1 = iVar2 == -1;
  if (bVar1) {
    iVar2 = FUN_0016b534();
  }
  FUN_0016baa0(iVar2,(u8)(bVar1));
}
