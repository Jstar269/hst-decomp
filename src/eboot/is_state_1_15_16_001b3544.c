/* HSTMATCH module=EBOOT.BIN start=0x001b3544 end=0x001b3590 symbol=FUN_001b3544 lang=c99 */
/* Clone of src/sharing_main/is_state_1_15_16_001c192c.c (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: range test rewritten as a switch with a result local, and the negative-index fallback as a ternary; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001b3544(int *param_1)
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
