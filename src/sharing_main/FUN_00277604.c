/* HSTMATCH module=hstp_trans_main.prx start=0x00277604 end=0x0027761c symbol=FUN_00277604 lang=c99 */
/* Clone of src/eboot/FUN_002666fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00277604(int param_1,u8 param_2)
{
  if (*(int *)(param_1 + 0x70) != 0) {
    *(u8 *)(*(int *)(param_1 + 0x70) + 0xc0) = param_2;
  }
}
