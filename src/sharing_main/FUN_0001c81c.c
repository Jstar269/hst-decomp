/* HSTMATCH module=hstp_trans_main.prx start=0x0001c81c end=0x0001c848 symbol=FUN_0001c81c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003751d0;
extern u32 DAT_003b8efc;

void FUN_0001c81c(int param_1)
{
  if (DAT_003b8efc == 0) {
    DAT_003751d0 = param_1 + 0x7fffU & 0xffff8000;
  }
}
