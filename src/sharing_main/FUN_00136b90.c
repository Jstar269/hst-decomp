/* HSTMATCH module=hstp_trans_main.prx start=0x00136b90 end=0x00136b98 symbol=FUN_00136b90 lang=c99 */
/* Clone of src/eboot/FUN_0012b724.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00136b90(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x404) = param_2;
}
