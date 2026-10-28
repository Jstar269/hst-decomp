/* HSTMATCH module=hstp_trans_main.prx start=0x0028cba8 end=0x0028cbb0 symbol=FUN_0028cba8 lang=c99 */
/* Clone of src/eboot/FUN_001fba70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_0027de54(u32 *param_1,short param_2);

void FUN_0028cba8(int param_1,short param_2)
{
  FUN_0027de54((u32 *)((u32 *)(param_1 + -0x3c)),(short)(param_2));
}
