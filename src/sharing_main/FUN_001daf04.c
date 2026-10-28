/* HSTMATCH module=hstp_trans_main.prx start=0x001daf04 end=0x001daf64 symbol=FUN_001daf04 lang=c99 */
/* Clone of src/eboot/FUN_001cc7d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000149a8();
extern int FUN_00014a40();
extern void FUN_00197150();

void FUN_001daf04(int param_1,u32 param_2)
{
  u32 uVar1;
  int iVar2;
  
  uVar1 = FUN_00014a40(param_2);
  if (uVar1 < 0x10) {
    FUN_000149a8(param_1 + 0x114,param_2);
    iVar2 = *(int *)(param_1 + 0x15c);
    FUN_00197150(*(u32 *)(iVar2 + 0x20));
    *(u8 *)(iVar2 + 100) = 1;
  }
}
