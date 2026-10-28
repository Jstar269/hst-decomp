/* HSTMATCH module=hstp_trans_main.prx start=0x002416c4 end=0x00241714 symbol=FUN_002416c4 lang=c99 */
/* Clone of src/eboot/FUN_002315c4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * DAT_003f398c;
extern u8 DAT_003f39a8;
extern int FUN_00241380();
extern void FUN_0024476c();

void FUN_002416c4(void)
{
  if ((DAT_003f398c != (int *)0x0) && (FUN_00241380(DAT_003f398c), DAT_003f398c[1] == 1)) {
    FUN_0024476c((int *)&DAT_003f39a8);
  }
}
