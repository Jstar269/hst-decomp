/* HSTMATCH module=hstp_trans_main.prx start=0x00003938 end=0x00003978 symbol=FUN_00003938 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000111c0();

int FUN_00003938(int param_1,int param_2,int param_3)
{
  FUN_000111c0(param_3,param_1,param_2 - param_1);
  return param_3 + (param_2 - param_1);
}
