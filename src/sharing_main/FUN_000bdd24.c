/* HSTMATCH module=hstp_trans_main.prx start=0x000bdd24 end=0x000bdd78 symbol=FUN_000bdd24 lang=c99 */
/* Clone of src/eboot/FUN_000ba9e0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037b360;
extern u8 DAT_0037b370;

void FUN_000bdd24(u32 param_1,u32 *param_2)
{
  if (param_2 != (u32 *)0x0) {
    *param_2 = 0x5a4;
    param_2[1] = 0x5a4;
    param_2[2] = 1;
    param_2[3] = 0x10;
    param_2[4] = 0x20000;
    param_2[5] = 0x8000;
    param_2[6] = (unsigned int)(&DAT_0037b360);
    param_2[7] = (unsigned int)(&DAT_0037b370);
  }
}
