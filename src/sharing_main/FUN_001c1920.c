/* HSTMATCH module=hstp_trans_main.prx start=0x001c1920 end=0x001c192c symbol=FUN_001c1920 lang=c99 */
/* Clone of src/eboot/FUN_001b3538.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001c1920(int *param_1,u32 param_2)
{
  *(u32 *)(*param_1 + 0x7a0) = param_2;
}
