/* HSTMATCH module=hstp_trans_main.prx start=0x00157eec end=0x00157f0c symbol=FUN_00157eec lang=c99 */
/* Clone of src/eboot/FUN_0014c3d8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00239f98();

u32 FUN_00157eec(u32 param_1,int param_2)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_00239f98(param_2 + 0xf0);
  return *puVar1;
}
