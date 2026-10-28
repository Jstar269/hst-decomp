/* HSTMATCH module=hstp_trans_main.prx start=0x00297538 end=0x0029754c symbol=FUN_00297538 lang=c99 */
/* Clone of src/eboot/FUN_00285f28.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_00297538(u32 *param_1)
{
  *param_1 = 0;
  *(u8 *)(param_1 + 1) = 0;
  *(u8 *)((int)param_1 + 0xc5) = 0;
  return param_1;
}
