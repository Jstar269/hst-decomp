/* HSTMATCH module=hstp_trans_main.prx start=0x0024e55c end=0x0024e600 symbol=FUN_0024e55c lang=c99 */
/* Clone of src/eboot/dispatch_mode_transition_0023e3c4.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else to if (param_2 > 0); exact match verified; names and types await human review. */

#include "hst/types.h"

extern void FUN_002265f0(u32, int, int, u32);
extern void FUN_00226630(u32, int);
extern void FUN_0024e004(int, int, int);

void FUN_0024e55c(int param_1, int param_2, u32 param_3)
{
  if (param_2 > 0) {
    FUN_00226630(*(u32 *)(param_1 + 0x14c0), 0);
    FUN_0024e004(param_1, 1, -1);
    FUN_002265f0(*(u32 *)(param_1 + 0x14c0), 0, param_2, param_3);
  }
  else {
    FUN_00226630(*(u32 *)(param_1 + 0x14c0), 1);
    FUN_0024e004(param_1, 1, 0);
    FUN_002265f0(*(u32 *)(param_1 + 0x14c0), 1, param_2, param_3);
  }
}
