/* HSTMATCH module=hstp_trans_main.prx start=0x002914fc end=0x00291508 symbol=FUN_002914fc lang=c99 */
/* Clone of src/eboot/FUN_00280088.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * FUN_00263df4();

void FUN_002914fc(int param_1)
{
  FUN_00263df4(3,*(u32 *)(param_1 + 0xc));
}
