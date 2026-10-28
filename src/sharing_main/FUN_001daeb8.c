/* HSTMATCH module=hstp_trans_main.prx start=0x001daeb8 end=0x001daf04 symbol=FUN_001daeb8 lang=c99 */
/* Clone of src/eboot/FUN_001cc784.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000149a8();
extern int FUN_00014a40();

void FUN_001daeb8(int param_1,u32 param_2)
{
  u32 uVar1;
  
  uVar1 = FUN_00014a40(param_2);
  if (uVar1 < 0x10) {
    FUN_000149a8(param_1 + 0x104,param_2);
  }
}
