/* HSTMATCH module=hstp_trans_main.prx start=0x001f8dbc end=0x001f8dd0 symbol=FUN_001f8dbc lang=c99 */
/* Clone of src/eboot/FUN_001eab18.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001f8dbc(int *param_1)
{
  int iVar1;
  
  iVar1 = *param_1;
  *(u8 *)(iVar1 + 0x43c) = 1;
  *(u32 *)(iVar1 + 0x440) = 0;
}
