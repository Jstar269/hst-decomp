/* HSTMATCH module=hstp_trans_main.prx start=0x002a444c end=0x002a4454 symbol=FUN_002a444c lang=c99 */
/* Clone of src/eboot/FUN_00292e40.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002a444c(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x34) = param_2;
}
