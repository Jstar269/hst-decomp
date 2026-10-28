/* HSTMATCH module=EBOOT.BIN start=0x0004d280 end=0x0004d2cc symbol=FUN_0004d280 lang=c99 */
/* Clone of src/sharing_main/FUN_0004d5f8.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002bc410;
extern u32 * FUN_00022570();
extern u32 * FUN_00022668();

void FUN_0004d280(u32 param_1,u32 param_2)
{
  u8 auStack_40 [64];
  
  FUN_00022668(auStack_40,&DAT_002bc410);
  FUN_00022570(param_1,param_2,auStack_40);
}
