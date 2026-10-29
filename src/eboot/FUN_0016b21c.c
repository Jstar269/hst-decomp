/* HSTMATCH module=EBOOT.BIN start=0x0016b21c end=0x0016b270 symbol=FUN_0016b21c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_0016b21c.c, corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsBlock * FUN_0016bb88();

/* Returns entry `index` of the settings block, or null when the index is out of range. */
SettingsEntry * FUN_0016b21c(int index)
{
  SettingsBlock *settings;
  SettingsEntry *entry;
  
  settings = FUN_0016bb88();
  if (0 <= index && (index < SETTINGS_ENTRY_COUNT)) {
    entry = &settings->entries[index];
  }
  else {
    entry = 0;
  }
  return entry;
}
