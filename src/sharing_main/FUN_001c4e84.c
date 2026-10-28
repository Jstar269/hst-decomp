/* HSTMATCH module=hstp_trans_main.prx start=0x001c4e84 end=0x001c4ed0 symbol=FUN_001c4e84 lang=c99 */
/* Clone of src/eboot/FUN_001b71c4.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern void FUN_00063190();
extern void FUN_001c1a38();
extern void FUN_001c20b8();
extern void FUN_001c230c();

void FUN_001c4e84(void)
{
  FUN_00063190(3,0x80,0x80,0);
  FUN_001c20b8((int *)&DAT_003eaad8);
  FUN_001c230c((int *)&DAT_003eaad8);
  FUN_001c1a38((int *)&DAT_003eaad8);
}
