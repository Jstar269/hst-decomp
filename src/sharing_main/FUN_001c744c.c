/* HSTMATCH module=hstp_trans_main.prx start=0x001c744c end=0x001c7490 symbol=FUN_001c744c lang=c99 */
/* Clone of src/eboot/FUN_001b9760.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b25c4;
extern u32 * FUN_0001ec44();

u32 * FUN_001c744c(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b25c4);
  param_1[0xf] = 0;
  *(u8 *)(param_1 + 0x10) = 0;
  *(u8 *)((int)param_1 + 0x41) = 0;
  param_1[0x11] = 0;
  return param_1;
}
