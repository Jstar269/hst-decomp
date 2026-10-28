/* HSTMATCH module=hstp_trans_main.prx start=0x001db960 end=0x001db96c symbol=FUN_001db960 lang=c99 */
/* Clone of src/eboot/FUN_001cd284.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_001db960(int param_1)
{
  return *(u8 *)(*(int *)(param_1 + 0x15c) + 0x90);
}
