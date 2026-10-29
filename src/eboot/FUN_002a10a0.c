/* HSTMATCH module=EBOOT.BIN start=0x002a10a0 end=0x002a10d8 symbol=FUN_002a10a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/anim_host.h"

extern u32 FUN_0001342c(); /* random number */

/* Picks a random value from 150 to 299. */
void FUN_002a10a0(AnimHost *host)
{
  int rnd;
  
  rnd = FUN_0001342c();
  host->unk1d8 = rnd % 0x96 + 0x96;
}
