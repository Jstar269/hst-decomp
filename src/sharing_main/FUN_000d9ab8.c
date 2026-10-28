/* HSTMATCH module=hstp_trans_main.prx start=0x000d9ab8 end=0x000d9adc symbol=FUN_000d9ab8 lang=c99 */
/* Clone of src/eboot/FUN_000d5dc8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0000430c();

bool FUN_000d9ab8(u32 param_1,u32 param_2,u32 param_3)
{
  int iVar1;
  
  iVar1 = FUN_0000430c(param_2,param_3);
  return iVar1 < 0;
}
