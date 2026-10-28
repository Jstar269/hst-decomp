/* HSTMATCH module=hstp_trans_main.prx start=0x00061cb0 end=0x00061d00 symbol=FUN_00061cb0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0348;
extern u32 * FUN_0006163c();

u32 * FUN_00061cb0(u32 *param_1)
{
  FUN_0006163c();
  *param_1 = (unsigned int)(&DAT_003b0348);
  param_1[0x20] = 0x42340000;
  param_1[0x21] = 0x3e4ccccd;
  param_1[0x22] = 0x447a0000;
  return param_1;
}
