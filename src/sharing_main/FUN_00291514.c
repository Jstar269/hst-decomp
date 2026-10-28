/* HSTMATCH module=hstp_trans_main.prx start=0x00291514 end=0x00291520 symbol=FUN_00291514 lang=c99 */
/* Clone of src/eboot/FUN_002800a0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * FUN_00263df4();

void FUN_00291514(int param_1)
{
  FUN_00263df4(5,*(u32 *)(param_1 + 0x14));
}
