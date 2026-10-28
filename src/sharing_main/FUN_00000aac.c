/* HSTMATCH module=hstp_trans_main.prx start=0x00000aac end=0x00000b08 symbol=FUN_00000aac lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b01b4;
extern u8 DAT_003b01a4;
extern void FUN_00000a00();

u32 * FUN_00000aac(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b01b4);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b01a4);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
