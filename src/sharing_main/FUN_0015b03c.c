/* HSTMATCH module=hstp_trans_main.prx start=0x0015b03c end=0x0015b050 symbol=FUN_0015b03c lang=c99 */
/* Clone of src/eboot/FUN_0014f028.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_0015b03c(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = *(u32 *)*param_1;
  *param_1 = (unsigned int)((u32 *)*param_1 + 1);
  return uVar1;
}
