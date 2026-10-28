/* HSTMATCH module=hstp_trans_main.prx start=0x001c192c end=0x001c1978 symbol=FUN_001c192c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: range test rewritten as a switch with a result local, and the negative-index fallback as a ternary; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001c192c(int *param_1)
{
  int iVar1;
  int r;

  iVar1 = *(int *)(*param_1 + 0x79c);
  iVar1 = (iVar1 < 0) ? *(int *)(*param_1 + 0x7a0) : iVar1;
  r = 0;
  switch (iVar1) {
  case 1:
  case 0xf:
  case 0x10:
    r = 1;
  }
  return r;
}
