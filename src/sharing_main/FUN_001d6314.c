/* HSTMATCH module=hstp_trans_main.prx start=0x001d6314 end=0x001d6320 symbol=FUN_001d6314 lang=c99 */
/* Clone of src/eboot/FUN_001c7e80.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001d6314(int param_1,u32 param_2,u32 param_3)
{
  *(u32 *)(param_1 + 0x14c) = param_2;
  *(u32 *)(param_1 + 0x150) = param_3;
}
