/* HSTMATCH module=hstp_trans_main.prx start=0x00138c5c end=0x00138c6c symbol=FUN_00138c5c lang=c99 */
/* Clone of src/eboot/FUN_0012d75c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_00138c5c(int param_1)
{
  return *(int *)(*(int *)(param_1 + 4) + 0x8c) != 0;
}
