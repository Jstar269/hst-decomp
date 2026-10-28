/* HSTMATCH module=hstp_trans_main.prx start=0x0015b050 end=0x0015b064 symbol=FUN_0015b050 lang=c99 */
/* Clone of src/eboot/FUN_0014f050.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u16 FUN_0015b050(u32 *param_1)
{
  u16 uVar1;
  
  uVar1 = *(u16 *)*param_1;
  *param_1 = (unsigned int)((u16 *)*param_1 + 1);
  return uVar1;
}
