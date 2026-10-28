/* HSTMATCH module=hstp_trans_main.prx start=0x000559f4 end=0x00055a28 symbol=FUN_000559f4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b02a0;
extern void FUN_00055ad0();

u32 * FUN_000559f4(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b02a0);
  FUN_00055ad0();
  return param_1;
}
