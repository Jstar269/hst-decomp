/* HSTMATCH module=hstp_trans_main.prx start=0x00051964 end=0x000519d4 symbol=FUN_00051964 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0294;
extern void FUN_00051a2c();
extern void FUN_00051b88();

u32 * FUN_00051964(u32 *param_1,u32 param_2,u32 param_3,u32 param_4)
{
  *param_1 = (unsigned int)(&DAT_003b0294);
  FUN_00051a2c();
  FUN_00051b88(param_1,param_2,param_3,param_4,0x10);
  return param_1;
}
