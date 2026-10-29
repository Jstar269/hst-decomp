/* HSTMATCH module=EBOOT.BIN start=0x001ff5a4 end=0x001ff5d0 symbol=FUN_001ff5a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/record_bank.h"

extern RecordRoot * DAT_003386c8;
extern void FUN_00281090();

/* Pass the record owner on to FUN_00281090 when the root exists. */
void FUN_001ff5a4(void)
{
  if (DAT_003386c8 != 0) {
    FUN_00281090(DAT_003386c8->owner);
  }
}
