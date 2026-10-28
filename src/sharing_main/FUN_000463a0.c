/* HSTMATCH module=hstp_trans_main.prx start=0x000463a0 end=0x00046400 symbol=FUN_000463a0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();

u32 * FUN_000463a0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    if ((*param_1 & 1) != 0) {
      FUN_00000a00(param_1[2]);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
