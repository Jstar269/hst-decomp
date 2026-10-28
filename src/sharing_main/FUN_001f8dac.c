/* HSTMATCH module=hstp_trans_main.prx start=0x001f8dac end=0x001f8dbc symbol=FUN_001f8dac lang=c99 */
/* Clone of src/eboot/FUN_001eab08.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001f8dac(int *param_1)
{
  return *(int *)(*param_1 + 0x3e4) != 0;
}
