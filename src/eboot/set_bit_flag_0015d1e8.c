/* HSTMATCH module=EBOOT.BIN start=0x0015d1e8 end=0x0015d244 symbol=FUN_0015d1e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the shifted bit is a signed char local OR-ed into the byte field (seb/andi, no shift mask); exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

extern code * FUN_0022cd60();

void FUN_0015d1e8(u32 param_1)
{
  int iVar1;
  signed char m;
  iVar1 = (int)(FUN_0022cd60());
  m = 1 << param_1;
  *(u8 *)(iVar1 + 0xf0) |= m;
  if (param_1 == 0) {
    *(u8 *)(iVar1 + 0x13c) = 1;
  }
  else if (param_1 == 2) {
    *(u8 *)(iVar1 + 0x13d) = 1;
  }
}
