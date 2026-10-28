/* HSTMATCH module=hstp_trans_main.prx start=0x000bfb34 end=0x000bfba0 symbol=FUN_000bfb34 lang=c99 */
/* Clone of src/eboot/FUN_000bc6c0.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the tested member passed to the free call (Ghidra dropped the argument); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0698;
extern void FUN_00000a00();
extern void FUN_000104e0();

u32 * FUN_000bfb34(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0698);
    if (param_1[6] != 0) {
      FUN_000104e0(param_1[6]);
      param_1[6] = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
