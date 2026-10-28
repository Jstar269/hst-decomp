/* HSTMATCH module=hstp_trans_main.prx start=0x001a572c end=0x001a5734 symbol=FUN_001a572c lang=c99 */
/* Clone of src/eboot/FUN_00198d28.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001a572c(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x98) = param_2;
}
