/* HSTMATCH module=hstp_trans_main.prx start=0x0017bef0 end=0x0017bf54 symbol=FUN_0017bef0 lang=c99 */
/* Clone of src/eboot/FUN_0016fca4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

void FUN_0017bef0(int param_1)
{
  u32 iVar1;
  int iVar3;
  int iVar2;
  
  if (*(u8 *)(param_1 + 0x46) != '\0') {
    iVar3 = 0;
    iVar2 = param_1;
    do {
      iVar1 = (**(code **)(param_1 + 1000))(iVar3);
      iVar3 = iVar3 + 1;
      *(short *)(iVar1 + 2) = (short)*(u32 *)(iVar2 + 0xfc);
      iVar2 = iVar2 + 4;
    } while (iVar3 < 0xf);
  }
}
