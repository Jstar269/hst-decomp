/* HSTMATCH module=hstp_trans_main.prx start=0x001e4054 end=0x001e4070 symbol=FUN_001e4054 lang=c99 */
/* Clone of src/eboot/FUN_001d6264.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001e4054(int param_1,u32 *param_2)
{
  if (param_2 != (u32 *)0x0) {
    *(u32 *)(param_1 + 8) = *param_2;
  }
  *(u32 *)(param_1 + 4) = 0;
}
