/* HSTMATCH module=hstp_trans_main.prx start=0x002b4168 end=0x002b41b0 symbol=FUN_002b4168 lang=c99 */
/* Clone of src/eboot/FUN_002a49d8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b31ac;
extern u32 DAT_003f469c;
extern u32 * FUN_0001ec44();
extern void FUN_002b46a8();

u32 * FUN_002b4168(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b31ac);
  DAT_003f469c = (unsigned int)(param_1);
  FUN_002b46a8(param_1,0);
  return param_1;
}
