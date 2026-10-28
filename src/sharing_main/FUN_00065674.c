/* HSTMATCH module=hstp_trans_main.prx start=0x00065674 end=0x000656e4 symbol=FUN_00065674 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b03f0;
extern u8 DAT_003b0414;
extern void FUN_000009e4();
extern void FUN_00000a00();

u32 * FUN_00065674(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b03f0);
    FUN_000009e4(param_1[1]);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b0414);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
