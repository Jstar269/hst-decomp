/* HSTMATCH module=hstp_trans_main.prx start=0x000039d4 end=0x000039e8 symbol=FUN_000039d4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_000039d4(int param_1,int param_2)
{
  return ~(param_2 - 1U) & param_1 + (param_2 - 1U);
}
