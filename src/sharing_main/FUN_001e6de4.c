/* HSTMATCH module=hstp_trans_main.prx start=0x001e6de4 end=0x001e6df4 symbol=FUN_001e6de4 lang=c99 */
/* Clone of src/eboot/FUN_001d9038.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001e6de4(int param_1)
{
  return *(int *)(param_1 + 4) == 1;
}
