/* HSTMATCH module=hstp_trans_main.prx start=0x0022f0e4 end=0x0022f110 symbol=FUN_0022f0e4 lang=c99 */
/* Clone of src/eboot/FUN_000eecc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();

void FUN_0022f0e4(int param_1)
{
  FUN_00108f54(param_1,0);
  *(u8 *)(param_1 + 0x54) = 0;
}
