/* HSTMATCH module=hstp_trans_main.prx start=0x00123f3c end=0x00123f44 symbol=FUN_00123f3c lang=c99 */
/* Clone of src/eboot/FUN_00118ad4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00128280();

void FUN_00123f3c(u32 param_1,int param_2)
{
  FUN_00128280(param_1,param_2,*(u32 *)(param_2 + 0x14));
}
