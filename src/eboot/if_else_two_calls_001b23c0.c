/* HSTMATCH module=EBOOT.BIN start=0x001b23c0 end=0x001b2430 symbol=FUN_001b23c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: swapped if/else order (param_2 != 0 first); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000622d4();

void FUN_001b23c0(u32 param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_000622d4(3,0x40,0x40,0xf);
    FUN_000622d4(2,0,0,3);
  }
  else {
    FUN_000622d4(3,0x80,0x80,0xf);
    FUN_000622d4(2,0x80,0x80,3);
  }
}
