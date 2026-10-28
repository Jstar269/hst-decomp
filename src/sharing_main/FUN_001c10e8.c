/* HSTMATCH module=hstp_trans_main.prx start=0x001c10e8 end=0x001c1138 symbol=FUN_001c10e8 lang=c99 */
/* Clone of src/eboot/FUN_001b2fb8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001be964();

void FUN_001c10e8(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = *param_1;
  FUN_001be964(uVar1,4,0,0,0);
  FUN_001be964(uVar1,0xad,0,0,0);
}
