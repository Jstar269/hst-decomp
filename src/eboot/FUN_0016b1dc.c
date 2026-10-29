/* HSTMATCH module=EBOOT.BIN start=0x0016b1dc end=0x0016b1fc symbol=FUN_0016b1dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsEntry * FUN_0016b21c();

/* Returns the flag byte of entry `index` of the settings block. */
u8 FUN_0016b1dc(int index)
{
  SettingsEntry *e;
  
  e = FUN_0016b21c(index);
  return e->unk1;
}
