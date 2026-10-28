/* HSTMATCH module=hstp_trans_main.prx start=0x0005f898 end=0x0005f8ec symbol=FUN_0005f898 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0318;
extern u32 * FUN_000559f4();
extern void FUN_0005f988();

u32 * FUN_0005f898(u32 *param_1)
{
  FUN_000559f4();
  *param_1 = (unsigned int)(&DAT_003b0318);
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  FUN_0005f988(param_1);
  return param_1;
}
