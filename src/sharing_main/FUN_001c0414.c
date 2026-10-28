/* HSTMATCH module=hstp_trans_main.prx start=0x001c0414 end=0x001c0454 symbol=FUN_001c0414 lang=c99 */
/* Clone of src/eboot/FUN_001b2380.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001be964();
extern void FUN_001bf834();

void FUN_001c0414(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = *param_1;
  FUN_001be964(uVar1,0x58,0,0,0);
  FUN_001bf834(uVar1);
}
