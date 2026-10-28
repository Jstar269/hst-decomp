/* HSTMATCH module=hstp_trans_main.prx start=0x001c1d84 end=0x001c1d9c symbol=FUN_001c1d84 lang=c99 */
/* Clone of src/eboot/FUN_001b39f4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0038d248;
extern void FUN_001be0d0();

void FUN_001c1d84(u32 *param_1)
{
  FUN_001be0d0(*param_1,&DAT_0038d248,9,0);
}
