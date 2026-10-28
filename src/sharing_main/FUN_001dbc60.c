/* HSTMATCH module=hstp_trans_main.prx start=0x001dbc60 end=0x001dbc68 symbol=FUN_001dbc60 lang=c99 */
/* Clone of src/eboot/FUN_001cd584.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001dbc60(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x168) = param_2;
}
