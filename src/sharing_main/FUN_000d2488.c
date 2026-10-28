/* HSTMATCH module=hstp_trans_main.prx start=0x000d2488 end=0x000d24e4 symbol=FUN_000d2488 lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b081c;
extern u8 DAT_003b0808;
extern void FUN_00000a00();

u32 * FUN_000d2488(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b081c);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b0808);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
