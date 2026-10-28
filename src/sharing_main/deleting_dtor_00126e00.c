/* HSTMATCH module=hstp_trans_main.prx start=0x00126e00 end=0x00126e8c symbol=FUN_00126e00 lang=c99 */
/* Clone of src/eboot/deleting_dtor_0011bba0.c (hstclone.py tag c41): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the cleared flag global DAT_003e47c0 typed as a u8; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b02f8;
extern u8 DAT_003b12ac;
extern unsigned char DAT_003e47c0;
extern u32 DAT_003e47c4;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern u32 * FUN_0005b0f4();

u32 * FUN_00126e00(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b12ac);
    DAT_003e47c0 = 0;
    DAT_003e47c4 = 0;
    if (param_1 + 0x10 != (u32 *)0x0) {
      param_1[0x10] = (unsigned int)(&DAT_003b02f8);
      FUN_0005b0f4(param_1 + 0x10,0);
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
