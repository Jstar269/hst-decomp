/* HSTMATCH module=EBOOT.BIN start=0x001e59f4 end=0x001e5a34 symbol=FUN_001e59f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_001e2694 as receiver-only; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001e2694(int);
extern void FUN_00222bb8();

void FUN_001e59f4(int param_1,u32 param_2)
{
  FUN_001e2694(param_1);
  FUN_00222bb8(*(u32 *)(param_1 + 0x1954),param_2,1);
}
