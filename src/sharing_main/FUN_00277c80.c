/* HSTMATCH module=hstp_trans_main.prx start=0x00277c80 end=0x00277c88 symbol=FUN_00277c80 lang=c99 */
/* Clone of src/eboot/FUN_00266d04.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00277c80(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x1f8) = param_2;
}
