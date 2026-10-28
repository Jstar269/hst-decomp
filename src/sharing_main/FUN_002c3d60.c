/* HSTMATCH module=hstp_trans_main.prx start=0x002c3d60 end=0x002c3d74 symbol=FUN_002c3d60 lang=c99 */
/* Clone of src/eboot/FUN_002b42a0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_002c3d60(int param_1,int param_2)
{
  return *(int *)(param_2 + 0x50) < *(int *)(*(int *)(param_1 + 4) + 0x50);
}
