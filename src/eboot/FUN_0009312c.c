/* HSTMATCH module=EBOOT.BIN start=0x0009312c end=0x00093194 symbol=FUN_0009312c lang=c99 data=0x002d2a54 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d2a54-0x002d2a63) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern char * FUN_00014d64(); /* substring search */

/* Mirror a bone name in place: "Bip01R..." becomes "Bip01L..." and "Bip01L..." becomes "Bip01R...". */
u32 FUN_0009312c(char *name)
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
