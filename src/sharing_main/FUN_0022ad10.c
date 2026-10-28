/* HSTMATCH module=hstp_trans_main.prx start=0x0022ad10 end=0x0022ad48 symbol=FUN_0022ad10 lang=c99 */
/* Clone of src/eboot/FUN_0021b79c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();

void FUN_0022ad10(int param_1)
{
  FUN_00108f54(param_1,1);
  *(u8 *)(param_1 + 0x54) = 1;
  *(u32 *)(param_1 + 100) = 0xffffffff;
}
