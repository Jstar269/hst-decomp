/* HSTMATCH module=hstp_trans_main.prx start=0x000577ec end=0x00057840 symbol=FUN_000577ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b02c4;
extern void FUN_000579bc();
extern u32 * FUN_0005f898();

u32 * FUN_000577ec(u32 *param_1)
{
  FUN_0005f898();
  *param_1 = (unsigned int)(&DAT_003b02c4);
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  FUN_000579bc(param_1);
  return param_1;
}
