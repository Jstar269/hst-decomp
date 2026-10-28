/* HSTMATCH module=hstp_trans_main.prx start=0x000d89c4 end=0x000d8a24 symbol=FUN_000d89c4 lang=c99 */
/* Clone of src/eboot/FUN_000d4cd4.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0718;
extern void FUN_000007f4();
extern u32 * FUN_0001ec44();
extern void FUN_000d8acc();
extern void FUN_000577ec();
extern void FUN_00057904();

u32 * FUN_000d89c4(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b0718);
  FUN_000007f4(param_1 + 0x14,FUN_000577ec,FUN_00057904,0x1b0,4);
  *(u8 *)(param_1 + 0x1c4) = 0;
  FUN_000d8acc(param_1);
  return param_1;
}
