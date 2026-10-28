/* HSTMATCH module=hstp_trans_main.prx start=0x00063810 end=0x00063854 symbol=FUN_00063810 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: used an early negative return and typed both helper prototypes; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00063908(u32, int);
extern void FUN_00077c58(int);

void FUN_00063810(u32 param_1,int param_2)
{
  if (param_2 < 0) return;
  FUN_00077c58(param_2);
  FUN_00063908(param_1,param_2);
}
