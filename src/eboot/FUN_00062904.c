/* HSTMATCH module=EBOOT.BIN start=0x00062904 end=0x0006294c symbol=FUN_00062904 lang=c99 */
/* Clone of src/sharing_main/FUN_000637c8.c (hstclone.py tag u5cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: direct negative early return reproduces bltz and the argument-save delay slot; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00062a44();
extern void FUN_00076454();

void FUN_00062904(u32 param_1,int param_2)
{
  if (param_2 < 0) return;
  FUN_00076454(param_2,0);
  FUN_00062a44(param_1,param_2);
}
