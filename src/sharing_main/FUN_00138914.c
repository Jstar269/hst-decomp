/* HSTMATCH module=hstp_trans_main.prx start=0x00138914 end=0x00138954 symbol=FUN_00138914 lang=c99 */
/* Clone of src/eboot/FUN_0012d414.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00055be8();

void FUN_00138914(int param_1,u32 param_2)
{
  FUN_00055be8(*(u32 *)(param_1 + 4));
  FUN_00055be8(*(u32 *)(param_1 + 0xc),param_2);
}
