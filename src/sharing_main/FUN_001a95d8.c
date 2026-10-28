/* HSTMATCH module=hstp_trans_main.prx start=0x001a95d8 end=0x001a9618 symbol=FUN_001a95d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b251c;
extern u8 DAT_003f39a8;
extern u32 * FUN_0001ec44();
extern void FUN_002446f8();

u32 * FUN_001a95d8(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b251c);
  FUN_002446f8(&DAT_003f39a8);
  return param_1;
}
