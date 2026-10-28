/* HSTMATCH module=hstp_trans_main.prx start=0x0020c850 end=0x0020c8ac symbol=FUN_0020c850 lang=c99 */
/* Clone of src/eboot/FUN_001fe080.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003751d4;
extern bool FUN_0001e6b0();

u8 FUN_0020c850(u32 param_1,u32 param_2,u32 param_3)
{
  u8 uVar1;
  
  uVar1 = FUN_0001e6b0(DAT_003751d4,param_1,param_2,2,9);
  if ((*(u32 *)(DAT_003751d4 + 0x80) & param_3) != 0) {
    uVar1 = 0;
  }
  return uVar1;
}
