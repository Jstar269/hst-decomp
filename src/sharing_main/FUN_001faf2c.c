/* HSTMATCH module=hstp_trans_main.prx start=0x001faf2c end=0x001faf34 symbol=FUN_001faf2c lang=c99 */
/* Clone of src/eboot/FUN_001ecbbc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001faf2c(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 8) = param_2;
}
