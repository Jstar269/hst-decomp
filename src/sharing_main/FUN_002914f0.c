/* HSTMATCH module=hstp_trans_main.prx start=0x002914f0 end=0x002914fc symbol=FUN_002914f0 lang=c99 */
/* Clone of src/eboot/FUN_0028007c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * FUN_00263df4();

void FUN_002914f0(int param_1)
{
  FUN_00263df4(2,*(u32 *)(param_1 + 8));
}
