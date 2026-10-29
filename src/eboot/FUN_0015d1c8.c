/* HSTMATCH module=EBOOT.BIN start=0x0015d1c8 end=0x0015d1e8 symbol=FUN_0015d1c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/profile_data.h"

extern ProfileData *DAT_00340400;

/* Returns the profile counter for id, or 0 when no profile is set. */
u8 FUN_0015d1c8(u32 unused,int id)
{
  u8 count;
  
  count = 0;
  if (DAT_00340400 != 0) {
    count = DAT_00340400->counts[id];
  }
  return count;
}
