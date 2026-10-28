/* HSTMATCH module=hstp_trans_main.prx start=0x002bd64c end=0x002bd670 symbol=FUN_002bd64c lang=c99 */
/* Clone of src/eboot/FUN_002ade24.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0001100c();

bool FUN_002bd64c(u32 param_1,u32 param_2)
{
  int iVar1;
  
  iVar1 = FUN_0001100c(param_1,param_2,0x10);
  return iVar1 == 0;
}
