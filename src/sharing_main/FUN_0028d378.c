/* HSTMATCH module=hstp_trans_main.prx start=0x0028d378 end=0x0028d388 symbol=FUN_0028d378 lang=c99 */
/* Clone of src/eboot/FUN_0027c008.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0028d378(int param_1)
{
  *(u32 *)(param_1 + 0x78) = 0xffffffff;
  *(u32 *)(param_1 + 0x7c) = 0xffffffff;
}
