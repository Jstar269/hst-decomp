/* HSTMATCH module=hstp_trans_main.prx start=0x00123ca8 end=0x00123cb0 symbol=FUN_00123ca8 lang=c99 */
/* Clone of src/eboot/FUN_00118ad4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001284e8();

void FUN_00123ca8(u32 param_1,int param_2)
{
  FUN_001284e8(param_1,param_2,*(u32 *)(param_2 + 0x14));
}
