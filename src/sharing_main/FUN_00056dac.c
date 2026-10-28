/* HSTMATCH module=hstp_trans_main.prx start=0x00056dac end=0x00056de8 symbol=FUN_00056dac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00056ecc();

u32 * FUN_00056dac(u32 *param_1,u32 param_2)
{
  FUN_00056ecc(param_1);
  *param_1 = param_2;
  *(u8 *)(param_1 + 2) = 0;
  return param_1;
}
