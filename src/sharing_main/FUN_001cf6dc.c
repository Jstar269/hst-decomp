/* HSTMATCH module=hstp_trans_main.prx start=0x001cf6dc end=0x001cf72c symbol=FUN_001cf6dc lang=c99 */
/* Clone of src/eboot/FUN_001c14c8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001ccd50();
extern void FUN_001cf558();

void FUN_001cf6dc(u32 *param_1)
{
  int iVar1;
  
  FUN_001ccd50(*param_1);
  *(u16 *)(param_1 + 0x104) = 0;
  FUN_001cf558(param_1);
  iVar1 = 0;
  do {
    *(u8 *)((int)param_1 + 0x412) = 0;
    iVar1 = iVar1 + 1;
    *(u8 *)((int)param_1 + 0x413) = 0;
    param_1 = (u32 *)((int)param_1 + 2);
  } while (iVar1 < 2);
}
