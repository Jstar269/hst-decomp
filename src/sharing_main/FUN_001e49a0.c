/* HSTMATCH module=hstp_trans_main.prx start=0x001e49a0 end=0x001e49b8 symbol=FUN_001e49a0 lang=c99 */
/* Clone of src/eboot/FUN_001d6bb0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_001e49a0(u32 *param_1)
{
  *param_1 = 0;
  *(u16 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *(u8 *)(param_1 + 3) = 0;
  return param_1;
}
