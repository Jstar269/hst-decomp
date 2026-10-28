/* HSTMATCH module=hstp_trans_main.prx start=0x001760cc end=0x001760e8 symbol=FUN_001760cc lang=c99 */
/* Clone of src/eboot/FUN_00169f08.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0000c6f4(float param_1,float param_2);

void FUN_001760cc(float *param_1,float *param_2)
{
  FUN_0000c6f4(*param_2 - *param_1,param_2[2] - param_1[2]);
}
