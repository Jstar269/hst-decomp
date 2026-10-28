/* HSTMATCH module=hstp_trans_main.prx start=0x002352dc end=0x002352e8 symbol=FUN_002352dc lang=c99 */
/* Clone of src/eboot/FUN_00225d68.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00233178();

void FUN_002352dc(int param_1)
{
  FUN_00233178(*(u32 *)(*(int *)(param_1 + 0x3c) + 0x20));
}
