/* HSTMATCH module=EBOOT.BIN start=0x00091bc8 end=0x00091c48 symbol=FUN_00091bc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: loop form and local declaration order; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002beb30;
extern void FUN_000006e8();
extern void FUN_00091af4();
extern void FUN_00092c38();
extern void FUN_00092dc8();
extern void FUN_0006e024();

void FUN_00091bc8(int param_1)
{
  int iVar2;
  u32 *puVar1;
  
  FUN_00092dc8();
  iVar2 = 5;
  puVar1 = (unsigned int *)(&DAT_002beb30);
  for (; iVar2 >= 0; iVar2--, puVar1--) {
    FUN_00092c38(param_1,*puVar1);
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    FUN_000006e8(*(int *)(param_1 + 0x24),FUN_0006e024);
    *(u32 *)(param_1 + 0x24) = 0;
  }
  FUN_00091af4(param_1);
}
