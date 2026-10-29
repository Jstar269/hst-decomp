/* HSTMATCH module=hstp_trans_main.prx start=0x002b0468 end=0x002b04ac symbol=FUN_002b0468 lang=c99 */
/* Clone of src/eboot/FUN_002a105c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/anim_host.h"

extern u32 FUN_0001342c(); /* random number */

/* Picks a random value from 120 to 450 in steps of 30. */
void FUN_002b0468(AnimHost *host)
{
  int rnd;
  
  rnd = FUN_0001342c();
  host->unk1f0 = (rnd % 0xc) * 0x1e + 0x78;
}
