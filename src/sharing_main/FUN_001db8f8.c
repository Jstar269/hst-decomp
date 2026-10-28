/* HSTMATCH module=hstp_trans_main.prx start=0x001db8f8 end=0x001db90c symbol=FUN_001db8f8 lang=c99 */
/* Clone of src/eboot/FUN_001cd190.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001db8f8(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x15c) + 4) == 10;
}
