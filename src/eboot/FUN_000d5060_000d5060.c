/* HSTMATCH module=EBOOT.BIN start=0x000d5060 end=0x000d50dc symbol=FUN_000d5060 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v3) corrected by hand: made the early gate explicit and reordered the loop locals for retail register allocation; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003386b0;
extern void FUN_0005f1e8();

void FUN_000d5060(int param_1)
{
  int iVar2;
  int iVar1;
  int self;
  
  if (*(u8 *)(param_1 + 0x710) != '\0') return;
  iVar2 = 0;
  iVar1 = 0;
  self = param_1;
  do {
    if (*(int *)(DAT_003386b0 + iVar1 + 0x70) != 0) {
      FUN_0005f1e8(self + 0x50,0);
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 4;
    self = self + 0x1b0;
  } while (iVar2 < 4);
}
