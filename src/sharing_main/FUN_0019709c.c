/* HSTMATCH module=hstp_trans_main.prx start=0x0019709c end=0x001970ac symbol=FUN_0019709c lang=c99 */
/* Clone of src/eboot/FUN_0018a950.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00113a50();

void FUN_0019709c(int param_1,u32 param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x78);
  *(u32 *)(iVar1 + 0xf8) = param_2;
  *(u32 *)(iVar1 + 0x138) = 0;
  FUN_00113a50(iVar1);
}
