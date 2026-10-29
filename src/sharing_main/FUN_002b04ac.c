/* HSTMATCH module=hstp_trans_main.prx start=0x002b04ac end=0x002b04e4 symbol=FUN_002b04ac lang=c99 */
/* Clone of src/eboot/FUN_002a10a0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/anim_host.h"

extern u32 FUN_0001342c(); /* random number */

/* Picks a random value from 150 to 299. */
void FUN_002b04ac(AnimHost *host)
{
  int rnd;
  
  rnd = FUN_0001342c();
  host->unk1d8 = rnd % 0x96 + 0x96;
}
