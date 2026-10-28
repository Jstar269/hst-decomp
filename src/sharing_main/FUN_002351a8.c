/* HSTMATCH module=hstp_trans_main.prx start=0x002351a8 end=0x002351b4 symbol=FUN_002351a8 lang=c99 */
/* Clone of src/eboot/FUN_00225c34.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0022ab4c();

void FUN_002351a8(int param_1)
{
  FUN_0022ab4c(*(u32 *)(*(int *)(param_1 + 0x3c) + 8));
}
