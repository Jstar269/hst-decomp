/* HSTMATCH module=hstp_trans_main.prx start=0x0016972c end=0x00169770 symbol=FUN_0016972c lang=c99 */
/* Clone of src/eboot/FUN_0015d184.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/profile_data.h"

extern ProfileData *DAT_003e9740;
extern u8 DAT_003ea34c;

/* Marks id in the flag table and bumps its profile counter up to the cap. */
void FUN_0016972c(u32 unused,int id)
{
  u8 count;
  
  (&DAT_003ea34c)[id] = 1;
  count = DAT_003e9740->counts[id];
  if (count < PROFILE_COUNT_MAX) {
    DAT_003e9740->counts[id] = count + 1;
  }
}
