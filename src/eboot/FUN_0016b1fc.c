/* HSTMATCH module=EBOOT.BIN start=0x0016b1fc end=0x0016b21c symbol=FUN_0016b1fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsEntry * FUN_0016b270();

/* Returns the flag byte of entry `index` of the static entry table. */
u8 FUN_0016b1fc(int index)
{
  SettingsEntry *e;
  
  e = FUN_0016b270(index);
  return e->unk1;
}
