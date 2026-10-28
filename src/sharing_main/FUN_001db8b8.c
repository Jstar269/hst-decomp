/* HSTMATCH module=hstp_trans_main.prx start=0x001db8b8 end=0x001db8cc symbol=FUN_001db8b8 lang=c99 */
/* Clone of src/eboot/FUN_001cd150.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001db8b8(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x15c) + 4) == 4;
}
