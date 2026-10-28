/* HSTMATCH module=EBOOT.BIN start=0x0012b760 end=0x0012b7cc symbol=FUN_0012b760 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reordered the conditions and grouped the signed offset expression; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0033b4b0;
extern u32 DAT_0033b4b4;

bool FUN_0012b760(int param_1)
{
  bool bVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x58) == 0) {
    bVar1 = false;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x58) + 0xf0);
    bVar1 = false;
    if (*(int *)(param_1 + 0x334) >= 0) {
      if (iVar2 == *(int *)(param_1 + 0x334)) {
        bVar1 = iVar2 <= (int)DAT_0033b4b4;
      }
    }
    else if (iVar2 == (int)DAT_0033b4b0 +
        (*(int *)(param_1 + 0x354) + (int)*(u8 *)(param_1 + 0x364) * 2)) {
      bVar1 = true;
    }
  }
  return bVar1;
}
