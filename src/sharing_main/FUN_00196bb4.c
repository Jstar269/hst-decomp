/* HSTMATCH module=hstp_trans_main.prx start=0x00196bb4 end=0x00196c40 symbol=FUN_00196bb4 lang=c99 */
/* Clone of src/eboot/FUN_0018a468.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b23ac;
extern u8 DAT_003b23f0;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();
extern u32 * FUN_0022651c();

u32 * FUN_00196bb4(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b23ac);
    param_1[0x34] = (unsigned int)(&DAT_003b23f0);
    FUN_0022651c(param_1 + 0x34,0);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b0a68);
      FUN_0010642c(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
