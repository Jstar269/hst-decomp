/* HSTMATCH module=EBOOT.BIN start=0x0016ba78 end=0x0016baa0 symbol=FUN_0016ba78 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsBlock * FUN_0016bb88();

/* Stores the flag byte at +0x103c. */
void FUN_0016ba78(u8 value)
{
  SettingsBlock *settings;
  
  settings = FUN_0016bb88();
  settings->unk103c = value;
}
