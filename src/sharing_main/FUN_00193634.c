/* HSTMATCH module=hstp_trans_main.prx start=0x00193634 end=0x00193664 symbol=FUN_00193634 lang=c99 */
/* Clone of src/eboot/FUN_00186ee8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108558();

void FUN_00193634(int param_1,int param_2)
{
  *(u8 *)(param_1 + 0x1250) = 0;
  *(float *)(*(int *)(param_1 + 0x28) + 0x60) =
       (float)(*(int *)(param_1 + 0x1238) - *(int *)(param_1 + 0x123c) * param_2);
  FUN_00108558(*(u32 *)(param_1 + 0x28));
}
