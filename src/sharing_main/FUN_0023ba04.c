/* HSTMATCH module=hstp_trans_main.prx start=0x0023ba04 end=0x0023ba20 symbol=FUN_0023ba04 lang=c99 */
/* Clone of src/eboot/FUN_0022bf94.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea8e8;
extern void FUN_001cdd24();

void FUN_0023ba04(u32 param_1,u32 param_2)
{
  FUN_001cdd24(DAT_003ea8e8 + 0x80,param_1,param_2,4);
}
