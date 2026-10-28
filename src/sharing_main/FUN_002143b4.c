/* HSTMATCH module=hstp_trans_main.prx start=0x002143b4 end=0x002143bc symbol=FUN_002143b4 lang=c99 */
/* Clone of src/eboot/FUN_00205b4c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002143b4(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x48) = param_2;
}
