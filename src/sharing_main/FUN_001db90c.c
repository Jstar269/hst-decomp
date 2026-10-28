/* HSTMATCH module=hstp_trans_main.prx start=0x001db90c end=0x001db920 symbol=FUN_001db90c lang=c99 */
/* Clone of src/eboot/FUN_001cd1a4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001db90c(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x15c) + 4) == 6;
}
