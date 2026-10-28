/* HSTMATCH module=hstp_trans_main.prx start=0x000518d4 end=0x00051908 symbol=FUN_000518d4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0294;
extern void FUN_00051a2c();

u32 * FUN_000518d4(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b0294);
  FUN_00051a2c();
  return param_1;
}
