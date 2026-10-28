/* HSTMATCH module=EBOOT.BIN start=0x001ec488 end=0x001ec518 symbol=FUN_001ec488 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: used a positive-count fast path and the named address symbol; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003386b0;
extern u8 DAT_0034179c;
extern u32 FUN_001b1c44();
extern void FUN_001ec564();

void FUN_001ec488(int param_1,int param_2,int param_3)
{
  *(int *)(param_1 + 0x14) = param_2;
  if (param_2 > 0) {
    FUN_001ec564(param_1,1,0);
  }
  else {
    if (((DAT_003386b0 == 0) ||
        ((*(int *)(DAT_003386b0 + 0x3c) != 9 && (*(int *)(DAT_003386b0 + 0x3c) != 2)))) &&
       (param_3 != 0)) {
      FUN_001b1c44(&DAT_0034179c,0xb);
    }
    FUN_001ec564(param_1,0,0);
  }
}
