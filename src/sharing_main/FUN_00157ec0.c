/* HSTMATCH module=hstp_trans_main.prx start=0x00157ec0 end=0x00157eec symbol=FUN_00157ec0 lang=c99 */
/* Clone of src/eboot/FUN_0014c3ac.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00239f98();

void FUN_00157ec0(u32 param_1,int param_2,u32 param_3)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_00239f98(param_2 + 0xf0);
  *puVar1 = param_3;
}
