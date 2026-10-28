/* HSTMATCH module=hstp_trans_main.prx start=0x001c1ec4 end=0x001c1edc symbol=FUN_001c1ec4 lang=c99 */
/* Clone of src/eboot/FUN_001b3b34.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0038d26c;
extern void FUN_001be0d0();

void FUN_001c1ec4(u32 *param_1)
{
  FUN_001be0d0(*param_1,&DAT_0038d26c,5,0);
}
