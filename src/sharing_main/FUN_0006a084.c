/* HSTMATCH module=hstp_trans_main.prx start=0x0006a084 end=0x0006a094 symbol=FUN_0006a084 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00069fd4();

void FUN_0006a084(u32 *param_1,u32 param_2,u32 param_3)
{
  *param_1 = param_2;
  FUN_00069fd4(param_1 + 1,param_3);
}
