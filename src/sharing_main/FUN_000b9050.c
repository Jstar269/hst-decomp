/* HSTMATCH module=hstp_trans_main.prx start=0x000b9050 end=0x000b9068 symbol=FUN_000b9050 lang=c99 */
/* Clone of src/eboot/FUN_000b5d60.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 * FUN_000b9050(u32 *param_1,u32 *param_2)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  return param_1;
}
