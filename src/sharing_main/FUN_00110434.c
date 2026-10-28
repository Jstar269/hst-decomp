/* HSTMATCH module=hstp_trans_main.prx start=0x00110434 end=0x00110444 symbol=FUN_00110434 lang=c99 */
/* Clone of src/eboot/FUN_0010a674.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_00110434(int param_1)
{
  return *(int *)(param_1 + 0x240) == 1;
}
