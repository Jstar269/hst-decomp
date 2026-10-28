/* HSTMATCH module=hstp_trans_main.prx start=0x00063854 end=0x00063888 symbol=FUN_00063854 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00063908();
extern void FUN_00077d4c();

void FUN_00063854(int param_1)
{
  FUN_00077d4c(*(u32 *)(param_1 + 4));
  FUN_00063908(param_1,*(u32 *)(param_1 + 0xc));
}
