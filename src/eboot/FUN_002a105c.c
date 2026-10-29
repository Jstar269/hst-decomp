/* HSTMATCH module=EBOOT.BIN start=0x002a105c end=0x002a10a0 symbol=FUN_002a105c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/anim_host.h"

extern u32 FUN_0001342c(); /* random number */

/* Picks a random value from 120 to 450 in steps of 30. */
void FUN_002a105c(AnimHost *host)
{
  int rnd;
  
  rnd = FUN_0001342c();
  host->unk1f0 = (rnd % 0xc) * 0x1e + 0x78;
}
