/* HSTMATCH module=hstp_trans_main.prx start=0x00064540 end=0x00064588 symbol=FUN_00064540 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0368;
extern u32 * FUN_00063e2c();

u32 * FUN_00064540(u32 *param_1)
{
  FUN_00063e2c();
  *param_1 = (unsigned int)(&DAT_003b0368);
  *(u8 *)(param_1 + 0x14) = 0;
  *(u8 *)((int)param_1 + 0x51) = 0;
  *(u8 *)((int)param_1 + 0x52) = 0;
  *(u8 *)((int)param_1 + 0x53) = 0;
  param_1[0x15] = 0;
  return param_1;
}
