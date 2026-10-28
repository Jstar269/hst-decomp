/* HSTMATCH module=hstp_trans_main.prx start=0x00136ae4 end=0x00136b54 symbol=FUN_00136ae4 lang=c99 */
/* Clone of src/eboot/FUN_0012b678.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001354c4();
extern u32 FUN_001377d0();
extern u32 FUN_00137a18();

void FUN_00136ae4(int param_1,u32 param_2,u32 param_3,u8 param_4)
{
  u8 cVar1;
  u8 uVar2;
  
  cVar1 = FUN_001377d0(param_1 + 0x370);
  if (cVar1 != '\0') {
    uVar2 = FUN_00137a18(param_1 + 0x370);
    *(u8 *)(param_1 + 0x410) = uVar2;
    *(u8 *)(param_1 + 0x32c) = param_4;
    if (*(u8 *)(param_1 + 0x410) == '\0') {
      FUN_001354c4(param_1,0xc,0xffffffff,0);
    }
  }
}
