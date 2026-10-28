/* HSTMATCH module=hstp_trans_main.prx start=0x001c14ac end=0x001c14c4 symbol=FUN_001c14ac lang=c99 */
/* Clone of src/eboot/FUN_001b322c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0038d2bc;
extern void FUN_001be0d0();

void FUN_001c14ac(u32 *param_1)
{
  FUN_001be0d0(*param_1,&DAT_0038d2bc,0x1a,0);
}
