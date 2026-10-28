/* HSTMATCH module=hstp_trans_main.prx start=0x001c0ed8 end=0x001c0f18 symbol=FUN_001c0ed8 lang=c99 */
/* Clone of src/eboot/FUN_001b2da8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00063304();

void FUN_001c0ed8(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0x2c0);
  if ((iVar1 != 0) && (iVar1 != 0)) {
    FUN_00063304(iVar1,1);
    *(u32 *)(iVar2 + 0x2c0) = 0;
  }
}
