/* HSTMATCH module=hstp_trans_main.prx start=0x001e4890 end=0x001e48a0 symbol=FUN_001e4890 lang=c99 */
/* Clone of src/eboot/FUN_001d6aa0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();

void FUN_001e4890(int param_1)
{
  *(u8 *)(param_1 + 0x54) = 0;
  *(u8 *)(param_1 + 0x55) = 0;
  FUN_00108f54(param_1,1);
}
