/* HSTMATCH module=EBOOT.BIN start=0x0017c344 end=0x0017c39c symbol=FUN_0017c344 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: corrected the helper return type and short-circuit returns; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_001fe848();
extern int FUN_001fe974();

int FUN_0017c344(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001fe974(param_1 + 0x2e4,*(u32 *)(param_1 + 4));
  if (iVar1 == 0) {
    iVar1 = FUN_001fe848(param_1 + 0x5c,*(u32 *)(param_1 + 4),0);
    if (iVar1 == 0) return 1;
  }
  return 0;
}
