/* HSTMATCH module=hstp_trans_main.prx start=0x001623e0 end=0x0016243c symbol=FUN_001623e0 lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b17d4;
extern void FUN_00000a00();
extern u32 * FUN_00157f20();

u32 * FUN_001623e0(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b17d4);
    FUN_00157f20(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
