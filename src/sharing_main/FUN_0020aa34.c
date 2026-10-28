/* HSTMATCH module=hstp_trans_main.prx start=0x0020aa34 end=0x0020aa8c symbol=FUN_0020aa34 lang=c99 */
/* Clone of src/eboot/FUN_001fc31c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2800;
extern u32 * FUN_0001ec44();
extern void FUN_0020ae30();

u32 * FUN_0020aa34(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b2800);
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  FUN_0020ae30(param_1,5);
  param_1[0x14] = 0;
  *(u8 *)(param_1 + 0x15) = 0;
  return param_1;
}
