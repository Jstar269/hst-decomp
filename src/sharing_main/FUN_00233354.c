/* HSTMATCH module=hstp_trans_main.prx start=0x00233354 end=0x0023338c symbol=FUN_00233354 lang=c99 */
/* Clone of src/eboot/FUN_00223de0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00105470();
extern void FUN_00108f54();

void FUN_00233354(int param_1)
{
  FUN_00108f54(param_1,0);
  *(u8 *)(param_1 + 0x54) = 0;
  FUN_00105470(*(u32 *)(param_1 + 100),1);
}
