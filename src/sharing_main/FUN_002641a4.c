/* HSTMATCH module=hstp_trans_main.prx start=0x002641a4 end=0x002641d4 symbol=FUN_002641a4 lang=c99 */
/* Clone of src/eboot/FUN_00118384.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_002641d4();

int FUN_002641a4(int param_1)
{
  FUN_002641d4();
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
