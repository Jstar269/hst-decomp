/* HSTMATCH module=hstp_trans_main.prx start=0x000963e0 end=0x000963ec symbol=FUN_000963e0 lang=c99 */
/* Clone of src/eboot/FUN_000944bc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000963e0(int param_1,u32 param_2,u32 param_3)
{
  *(u32 *)(param_1 + 0x20) = param_2;
  *(u32 *)(param_1 + 0x24) = param_3;
}
