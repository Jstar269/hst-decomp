/* HSTMATCH module=EBOOT.BIN start=0x00198d68 end=0x00198de0 symbol=FUN_00198d68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed range and null checks as ordered early returns; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000149a8();
extern int FUN_00014a40();

void FUN_00198d68(int param_1,int param_2,int param_3)
{
  u32 uVar1;

  if (param_2 < 0) return;
  if (param_2 >= 4) return;
  if (param_3 == 0) return;
  uVar1 = FUN_00014a40(param_3);
  if (uVar1 >= 8) return;
  FUN_000149a8(param_1 + param_2 * 8 + 0xa0,param_3);
}
