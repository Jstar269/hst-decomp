/* HSTMATCH module=hstp_trans_main.prx start=0x001d3560 end=0x001d356c symbol=FUN_001d3560 lang=c99 */
/* Clone of src/eboot/FUN_001c51c8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001d3560(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0xc4) = param_2;
  *(u32 *)(param_1 + 200) = 0;
}
