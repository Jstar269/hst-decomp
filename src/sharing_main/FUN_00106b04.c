/* HSTMATCH module=hstp_trans_main.prx start=0x00106b04 end=0x00106b90 symbol=FUN_00106b04 lang=c99 */
/* Clone of src/eboot/FUN_00101194.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the member argument Ghidra dropped from the call restored; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0e24;
extern u8 DAT_003b0e78;
extern void FUN_00000a00();
extern void FUN_000104e0();
extern u32 * FUN_000519d4();

u32 * FUN_00106b04(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0e78);
    if (param_1[0x14] != 0) {
      FUN_000104e0(param_1[0x14]);
      param_1[0x14] = 0;
    }
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b0e24);
      FUN_000519d4(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
