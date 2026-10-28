/* HSTMATCH module=hstp_trans_main.prx start=0x00002d08 end=0x00002d1c symbol=FUN_00002d08 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00002d08(u32 *param_1,u32 param_2,u8 *param_3)
{
  *(u8 *)param_1 = *param_3;
  *param_1 = param_2;
  return param_1;
}
