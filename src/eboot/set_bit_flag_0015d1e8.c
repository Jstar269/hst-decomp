/* HSTMATCH module=EBOOT.BIN start=0x0015d1e8 end=0x0015d244 symbol=FUN_0015d1e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the shifted bit is a signed char local OR-ed into the byte field (seb/andi, no shift mask); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/profile_data.h"

extern ProfileData * FUN_0022cd60();

/* Sets flag bit index in the profile; indexes 0 and 2 also set a companion byte. */
void FUN_0015d1e8(u32 index)
{
  ProfileData *profile;
  signed char mask;
  profile = FUN_0022cd60();
  mask = 1 << index;
  profile->flag_bits |= mask;
  if (index == 0) {
    profile->unk13c = 1;
  }
  else if (index == 2) {
    profile->unk13d = 1;
  }
}
