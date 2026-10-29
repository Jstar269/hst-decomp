/* HSTMATCH module=EBOOT.BIN start=0x0015d184 end=0x0015d1c8 symbol=FUN_0015d184 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/profile_data.h"

extern ProfileData *DAT_00340400;
extern u8 DAT_0034100c;

/* Marks id in the flag table and bumps its profile counter up to the cap. */
void FUN_0015d184(u32 unused,int id)
{
  u8 count;
  
  (&DAT_0034100c)[id] = 1;
  count = DAT_00340400->counts[id];
  if (count < PROFILE_COUNT_MAX) {
    DAT_00340400->counts[id] = count + 1;
  }
}
