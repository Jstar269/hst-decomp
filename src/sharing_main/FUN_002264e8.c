/* HSTMATCH module=hstp_trans_main.prx start=0x002264e8 end=0x0022651c symbol=FUN_002264e8 lang=c99 */
/* Clone of src/eboot/FUN_00217440.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2898;

u32 * FUN_002264e8(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b2898);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[7] = 0;
  *(u8 *)(param_1 + 8) = 0;
  *(u8 *)((int)param_1 + 0x21) = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return param_1;
}
