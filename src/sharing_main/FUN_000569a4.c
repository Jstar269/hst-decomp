/* HSTMATCH module=hstp_trans_main.prx start=0x000569a4 end=0x000569f4 symbol=FUN_000569a4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00056a44();
extern u32 FUN_00056a58();

u32 FUN_000569a4(u32 param_1,u32 param_2,u32 param_3)
{
  FUN_00056a44(param_1);
  FUN_00056a58(param_1,param_2,param_3);
  return param_1;
}
