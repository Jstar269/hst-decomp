/* HSTMATCH module=hstp_trans_main.prx start=0x002b0e58 end=0x002b0e70 symbol=FUN_002b0e58 lang=c99 */
/* Clone of src/eboot/FUN_002a1a4c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002b0e58(u32 *param_1,u32 param_2)
{
  *param_1 = param_2;
  *(u8 *)(param_1 + 1) = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  *(u8 *)(param_1 + 0x43) = 0;
}
