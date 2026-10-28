/* HSTMATCH module=EBOOT.BIN start=0x00150620 end=0x0015068c symbol=FUN_00150620 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py) corrected by hand: early `if (FUN(...) == 0) { ...; return 1; } return 0;` shape, int (not bool) return on the gate; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a114;
extern int FUN_0014c384();
extern int FUN_001cd150();
extern u8 FUN_001cd290();

bool FUN_00150620(int param_1,u32 *param_2)
{
  u32 v;

  if (FUN_001cd150(DAT_0034a114) == 0) {
    v = *param_2;
    *(u32 *)FUN_0014c384(v,*(u32 *)(*(int *)(param_1 + 4) + 0xc)) =
         FUN_001cd290(DAT_0034a114) & 0xff;
    return 1;
  }
  return 0;
}
