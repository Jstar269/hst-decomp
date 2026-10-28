/* HSTMATCH module=hstp_trans_main.prx start=0x00120ce4 end=0x00120cf8 symbol=FUN_00120ce4 lang=c99 */
/* Clone of src/eboot/FUN_00115dc8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00120ce4(int param_1,u32 param_2,u16 param_3,u16 param_4, u16 param_5,u16 param_6)
{
  *(u16 *)(param_1 + 0x130) = param_3;
  *(u16 *)(param_1 + 0x132) = param_4;
  *(u16 *)(param_1 + 0x134) = param_5;
  *(u16 *)(param_1 + 0x136) = param_6;
}
