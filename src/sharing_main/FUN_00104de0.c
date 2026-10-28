/* HSTMATCH module=hstp_trans_main.prx start=0x00104de0 end=0x00104e48 symbol=FUN_00104de0 lang=c99 */
/* Clone of src/eboot/FUN_000ff548.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the tested member passed to the free call (Ghidra dropped the argument); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0c40;
extern void FUN_00000a00();
extern void FUN_000104e0();

u32 * FUN_00104de0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0c40);
    if (param_1[1] != 0) {
      FUN_000104e0(param_1[1]);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
