/* HSTMATCH module=hstp_trans_main.prx start=0x001dfcd0 end=0x001dfd08 symbol=FUN_001dfcd0 lang=c99 */
/* Clone of src/eboot/FUN_001d1ecc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003751d4;
extern void FUN_0001dc34();
extern void FUN_0001de88();

void FUN_001dfcd0(void)
{
  FUN_0001dc34(DAT_003751d4,0x2000);
  FUN_0001de88(DAT_003751d4,0x2000,1);
}
