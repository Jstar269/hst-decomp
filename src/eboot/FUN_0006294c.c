/* HSTMATCH module=EBOOT.BIN start=0x0006294c end=0x00062990 symbol=FUN_0006294c lang=c99 */
/* Clone of src/sharing_main/FUN_00063810.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: used an early negative return and typed both helper prototypes; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00062a44(u32, int);
extern void FUN_00076498(int);

void FUN_0006294c(u32 param_1,int param_2)
{
  if (param_2 < 0) return;
  FUN_00076498(param_2);
  FUN_00062a44(param_1,param_2);
}
