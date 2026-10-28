/* HSTMATCH module=hstp_trans_main.prx start=0x0029f7f4 end=0x0029f83c symbol=FUN_0029f7f4 lang=c99 */
/* Clone of src/eboot/FUN_0028e02c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea8ec;
extern void FUN_00108f54();
extern void FUN_00292408();

void FUN_0029f7f4(int param_1)
{
  *(u8 *)(param_1 + 0x54) = 0;
  *(u8 *)(param_1 + 0x55) = 0;
  FUN_00108f54(param_1,1);
  FUN_00108f54(DAT_003ea8ec,1);
  FUN_00292408(*(u32 *)(param_1 + 0x640));
}
