/* HSTMATCH module=hstp_trans_main.prx start=0x0019f554 end=0x0019f59c symbol=FUN_0019f554 lang=c99 */
/* Clone of src/eboot/FUN_00192d44.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_0019f38c();
extern u32 * FUN_0019f7c8();

u32 * FUN_0019f554(u32 *param_1)
{
  FUN_0019f7c8(param_1 + 1);
  param_1[4] = 0;
  param_1[5] = 0;
  FUN_0019f38c(param_1 + 8);
  FUN_0019f38c(param_1 + 0x2c);
  *param_1 = 0;
  return param_1;
}
