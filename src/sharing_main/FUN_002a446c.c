/* HSTMATCH module=hstp_trans_main.prx start=0x002a446c end=0x002a44b8 symbol=FUN_002a446c lang=c99 */
/* Clone of src/eboot/FUN_00292e60.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b30b4;
extern u32 * FUN_002a308c();

u32 * FUN_002a446c(u32 *param_1)
{
  FUN_002a308c();
  *param_1 = (unsigned int)(&DAT_003b30b4);
  *(u8 *)(param_1 + 0x13) = 0;
  *(u8 *)((int)param_1 + 0x4d) = 0;
  param_1[0x14] = 0;
  *(u8 *)(param_1 + 0x15) = 0;
  *(u8 *)((int)param_1 + 0x4e) = 1;
  return param_1;
}
