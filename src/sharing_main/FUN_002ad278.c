/* HSTMATCH module=hstp_trans_main.prx start=0x002ad278 end=0x002ad284 symbol=FUN_002ad278 lang=c99 */
/* Clone of src/eboot/FUN_0022599c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_002ad278(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x3c) + 0x28);
}
