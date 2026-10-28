/* HSTMATCH module=hstp_trans_main.prx start=0x0029b2ec end=0x0029b304 symbol=FUN_0029b2ec lang=c99 */
/* Clone of src/eboot/FUN_000b5d60.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_0029b2ec(u32 *param_1,u32 *param_2)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  return param_1;
}
