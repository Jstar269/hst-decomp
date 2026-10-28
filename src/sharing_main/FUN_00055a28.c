/* HSTMATCH module=hstp_trans_main.prx start=0x00055a28 end=0x00055a6c symbol=FUN_00055a28 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b02a0;
extern void FUN_00055ad0();

u32 * FUN_00055a28(u32 *param_1,u32 param_2)
{
  *param_1 = (unsigned int)(&DAT_003b02a0);
  FUN_00055ad0();
  param_1[0x23] = param_2;
  return param_1;
}
