/* HSTMATCH module=hstp_trans_main.prx start=0x0003287c end=0x00032888 symbol=FUN_0003287c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00032770();

void FUN_0003287c(int param_1)
{
  FUN_00032770(param_1,*(u32 *)(param_1 + 4),param_1 + 0x18);
}
