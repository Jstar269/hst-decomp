/* HSTMATCH module=EBOOT.BIN start=0x0015d3fc end=0x0015d46c symbol=FUN_0015d3fc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/profile_data.h"

extern ProfileData * FUN_0022cd60(void);
extern u8 DAT_0034100c;

#define FLAG_TABLE_BASE 0xd0 /* first entry of the flag table checked by the scan */
/* the flag byte is read as a signed char */

/* Returns 1 when some profile flag bit is set while its flag-table entry is still clear. */
u8 FUN_0015d3fc(void)
{
  ProfileData *profile;
  int i;
  char *entry;
  unsigned char found;

  found = 0;
  profile = FUN_0022cd60();
  for (i = 0, entry = (char *)&DAT_0034100c; i < PROFILE_FLAG_BITS; i++, entry++) {
    if ((*(char *)&profile->flag_bits & (1 << i)) != 0 && entry[FLAG_TABLE_BASE] == '\0') {
      found = 1;
      break;
    }
  }
  return found;
}
