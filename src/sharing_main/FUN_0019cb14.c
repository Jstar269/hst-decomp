/* HSTMATCH module=hstp_trans_main.prx start=0x0019cb14 end=0x0019cb58 symbol=FUN_0019cb14 lang=c99 */
/* Clone of src/eboot/FUN_00190304.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2460;
extern u32 * FUN_0001ec44();
extern void FUN_001a57f4();
extern void FUN_001a58b8();

u32 * FUN_0019cb14(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b2460);
  FUN_001a57f4(param_1 + 0xf);
  FUN_001a58b8(param_1);
  return param_1;
}
