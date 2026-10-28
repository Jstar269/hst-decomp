/* HSTMATCH module=hstp_trans_main.prx start=0x0003cb18 end=0x0003cb28 symbol=FUN_0003cb18 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0003d9c0();

void FUN_0003cb18(int param_1)
{
  FUN_0003d9c0(*(u32 *)(param_1 + 0x81c),0,0);
}
