/* HSTMATCH module=EBOOT.BIN start=0x001aa244 end=0x001aa2a4 symbol=FUN_001aa244 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the switch value is read into a local before the pointer temporary is built (that order gives retail's a1/a0 register split); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0019d474();

void FUN_001aa244(int param_1)
{
  int iVar1;
  int *pp;
  int mode;

  mode = *(int *)(FUN_0019d474() + 0x2f4);
  pp = (int *)(param_1 + 0xc0);
  switch (mode) {
    case 0:
      iVar1 = *pp;
      *(u32 *)(iVar1 + 0x24) = *(u32 *)(iVar1 + 0x28);
      break;
    case 1:
      iVar1 = *pp;
      *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x28) + 1;
      break;
    default:
      break;
  }
}
