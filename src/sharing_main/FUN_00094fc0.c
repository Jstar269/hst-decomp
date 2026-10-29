/* HSTMATCH module=hstp_trans_main.prx start=0x00094fc0 end=0x00095028 symbol=FUN_00094fc0 lang=c99 data=0x00378d18 */
/* Clone of src/eboot/FUN_0009312c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00378d18-0x00378d27) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern char * FUN_00014d64(); /* substring search */

/* Mirror a bone name in place: "Bip01R..." becomes "Bip01L..." and "Bip01L..." becomes "Bip01R...". */
u32 FUN_00094fc0(char *name)
{
  char *found;

  if (name != 0) {
    found = FUN_00014d64(name,"Bip01R");
    if (found == name) {
      name[5] = 'L';
    }
    else {
      found = FUN_00014d64(name,"Bip01L");
      if (found == name) {
        name[5] = 'R';
      }
    }
  }
  return 0;
}
