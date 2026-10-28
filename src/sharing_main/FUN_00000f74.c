/* HSTMATCH module=hstp_trans_main.prx start=0x00000f74 end=0x00000f98 symbol=FUN_00000f74 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003b330c;

u32 FUN_00000f74(u32 param_1,u32 param_2,u32 *param_3)
{
  *param_3 = DAT_003b330c;
  param_3[1] = param_2;
  param_3[2] = param_1;
  DAT_003b330c = (unsigned int)(param_3);
  return param_1;
}
