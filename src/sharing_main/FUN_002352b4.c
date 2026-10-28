/* HSTMATCH module=hstp_trans_main.prx start=0x002352b4 end=0x002352c8 symbol=FUN_002352b4 lang=c99 */
/* Clone of src/eboot/FUN_00225d40.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0022fcdc();

void FUN_002352b4(int param_1,u32 param_2,u32 param_3)
{
  FUN_0022fcdc(*(u32 *)(*(int *)(param_1 + 0x3c) + 0x1c),param_2,0,param_3);
}
