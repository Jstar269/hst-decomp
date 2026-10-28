/* HSTMATCH module=hstp_trans_main.prx start=0x001c8a30 end=0x001c8a7c symbol=FUN_001c8a30 lang=c99 */
/* Clone of src/eboot/FUN_001bace8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_002134e8();

void FUN_001c8a30(int param_1,int param_2)
{
  FUN_002134e8(*(u32 *)(*(int *)(param_1 + 4) + param_2 * 4));
  *(u8 *)(param_2 + param_1 + 0x10) = 0;
  *(u8 *)(param_2 + param_1 + 0x14) = 0;
}
