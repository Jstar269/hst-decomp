/* HSTMATCH module=hstp_trans_main.prx start=0x002ad25c end=0x002ad26c symbol=FUN_002ad25c lang=c99 */
/* Clone of src/eboot/FUN_0029e0e0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_002ad25c(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x3c) + 8) != 0;
}
