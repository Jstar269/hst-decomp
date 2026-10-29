/* HSTMATCH module=hstp_trans_main.prx start=0x0020a188 end=0x0020a190 symbol=FUN_0020a188 lang=c99 */
/* Clone of src/eboot/FUN_001fba70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_001fcd94(u32 *self,short flag);

/* Destructor thunk: adjusts this by -0x3c (secondary base to full object) and forwards. */
void FUN_0020a188(int sub_object,short flag)
{
  FUN_001fcd94((u32 *)((u32 *)(sub_object + -0x3c)),(short)(flag));
}
