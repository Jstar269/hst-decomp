/* HSTMATCH module=hstp_trans_main.prx start=0x00051908 end=0x00051964 symbol=FUN_00051908 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0294;
extern void FUN_00051a2c();
extern void FUN_00051ad8();

u32 * FUN_00051908(u32 *param_1,u32 param_2,u32 param_3)
{
  *param_1 = (unsigned int)(&DAT_003b0294);
  FUN_00051a2c();
  FUN_00051ad8(param_1,param_2,param_3);
  return param_1;
}
