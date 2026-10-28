/* HSTMATCH module=hstp_trans_main.prx start=0x0017be94 end=0x0017bef0 symbol=FUN_0017be94 lang=c99 */
/* Clone of src/eboot/FUN_0016fc48.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

void FUN_0017be94(int param_1)
{
  int iVar1;
  int iVar3;
  int iVar2;
  
  iVar3 = 0;
  iVar2 = param_1;
  do {
    iVar1 = (**(code **)(param_1 + 1000))(iVar3);
    iVar3 = iVar3 + 1;
    *(char *)(iVar1 + 1) = (char)*(u32 *)(iVar2 + 0xc0);
    iVar2 = iVar2 + 4;
  } while (iVar3 < 0xf);
}
