/* HSTMATCH module=hstp_trans_main.prx start=0x0020d528 end=0x0020d55c symbol=FUN_0020d528 lang=c99 */
/* Clone of src/eboot/FUN_001fed58.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003da704;
extern void FUN_0005d68c();
extern void FUN_0005d7e8();

void FUN_0020d528(void)
{
  FUN_0005d7e8(DAT_003da704,0);
  FUN_0005d68c(DAT_003da704,0);
}
