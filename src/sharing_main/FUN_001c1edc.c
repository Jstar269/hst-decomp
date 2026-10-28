/* HSTMATCH module=hstp_trans_main.prx start=0x001c1edc end=0x001c1ef4 symbol=FUN_001c1edc lang=c99 */
/* Clone of src/eboot/FUN_001b3b4c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0038d280;
extern void FUN_001be0d0();

void FUN_001c1edc(u32 *param_1)
{
  FUN_001be0d0(*param_1,&DAT_0038d280,8,0);
}
