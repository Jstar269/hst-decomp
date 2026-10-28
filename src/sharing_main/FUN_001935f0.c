/* HSTMATCH module=hstp_trans_main.prx start=0x001935f0 end=0x00193634 symbol=FUN_001935f0 lang=c99 */
/* Clone of src/eboot/FUN_00186ea4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001935f0(int param_1,int param_2,int param_3)
{
  *(u8 *)(param_1 + 0x1250) = 1;
  *(int *)(param_1 + 0x1240) = *(int *)(param_1 + 0x1238) - *(int *)(param_1 + 0x123c) * param_2;
  *(int *)(param_1 + 0x1244) = *(int *)(param_1 + 0x1238) - *(int *)(param_1 + 0x123c) * param_3;
  *(u32 *)(param_1 + 0x124c) = 0;
  *(u32 *)(param_1 + 0x1248) = 0;
}
