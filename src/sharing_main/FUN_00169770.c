/* HSTMATCH module=hstp_trans_main.prx start=0x00169770 end=0x00169790 symbol=FUN_00169770 lang=c99 */
/* Clone of src/eboot/FUN_0015d1c8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/profile_data.h"

extern ProfileData *DAT_003e9740;

/* Returns the profile counter for id, or 0 when no profile is set. */
u8 FUN_00169770(u32 unused,int id)
{
  u8 count;
  
  count = 0;
  if (DAT_003e9740 != 0) {
    count = DAT_003e9740->counts[id];
  }
  return count;
}
