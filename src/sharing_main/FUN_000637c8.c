/* HSTMATCH module=hstp_trans_main.prx start=0x000637c8 end=0x00063810 symbol=FUN_000637c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: direct negative early return reproduces bltz and the argument-save delay slot; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00063908();
extern void FUN_00077c14();

void FUN_000637c8(u32 param_1,int param_2)
{
  if (param_2 < 0) return;
  FUN_00077c14(param_2,0);
  FUN_00063908(param_1,param_2);
}
