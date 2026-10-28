/* HSTMATCH module=hstp_trans_main.prx start=0x00242d08 end=0x00242d58 symbol=FUN_00242d08 lang=c99 */
/* Clone of src/eboot/FUN_00232c08.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f3994;
extern void FUN_00242dc4();
extern void FUN_0024312c();

u32 * FUN_00242d08(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  DAT_003f3994 = (unsigned int)(param_1);
  *(u8 *)(param_1 + 4) = 0;
  *(u8 *)((int)param_1 + 0x11) = 0;
  *(u8 *)((int)param_1 + 0x12) = 0;
  FUN_00242dc4();
  FUN_0024312c(param_1,9);
  return param_1;
}
