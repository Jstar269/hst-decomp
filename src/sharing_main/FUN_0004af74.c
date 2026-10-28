/* HSTMATCH module=hstp_trans_main.prx start=0x0004af74 end=0x0004afe4 symbol=FUN_0004af74 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0004b034();
extern u32 FUN_0004b044();

u32 FUN_0004af74(u32 param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5)
{
  FUN_0004b034(param_1);
  FUN_0004b044(param_1,param_2,param_3,param_4,param_5);
  return param_1;
}
