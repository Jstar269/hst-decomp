/* HSTMATCH module=hstp_trans_main.prx start=0x00226630 end=0x0022664c symbol=FUN_00226630 lang=c99 */
/* Clone of src/eboot/FUN_00217588.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00226630(int param_1,int param_2)
{
  *(u8 *)(param_1 + 0x20) = 0;
  *(int *)(param_1 + 0x1c) = -param_2 * *(int *)(param_1 + 8);
}
