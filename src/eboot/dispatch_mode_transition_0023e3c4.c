/* HSTMATCH module=EBOOT.BIN start=0x0023e3c4 end=0x0023e468 symbol=FUN_0023e3c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else to if (param_2 > 0); exact match verified; names and types await human review. */

#include "hst/types.h"

extern void FUN_00217548(u32, int, int, u32);
extern void FUN_00217588(u32, int);
extern void FUN_0023de6c(int, int, int);

void FUN_0023e3c4(int param_1, int param_2, u32 param_3)
{
  if (param_2 > 0) {
    FUN_00217588(*(u32 *)(param_1 + 0x14c0), 0);
    FUN_0023de6c(param_1, 1, -1);
    FUN_00217548(*(u32 *)(param_1 + 0x14c0), 0, param_2, param_3);
  }
  else {
    FUN_00217588(*(u32 *)(param_1 + 0x14c0), 1);
    FUN_0023de6c(param_1, 1, 0);
    FUN_00217548(*(u32 *)(param_1 + 0x14c0), 1, param_2, param_3);
  }
}
