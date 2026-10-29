/* HSTMATCH module=hstp_trans_main.prx start=0x002c4854 end=0x002c485c symbol=FUN_002c4854 lang=c99 */
/* Clone of src/eboot/FUN_001fba70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_002bf968(u32 *self,short flag);

/* Destructor thunk: adjusts this by -0x3c (secondary base to full object) and forwards. */
void FUN_002c4854(int sub_object,short flag)
{
  FUN_002bf968((u32 *)((u32 *)(sub_object + -0x3c)),(short)(flag));
}
