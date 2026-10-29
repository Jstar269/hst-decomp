/* HSTMATCH module=hstp_trans_main.prx start=0x001773e0 end=0x00177434 symbol=FUN_001773e0 lang=c99 */
/* Clone of src/eboot/FUN_0016b21c.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsBlock * FUN_00177d4c();

/* Returns entry `index` of the settings block, or null when the index is out of range. */
SettingsEntry * FUN_001773e0(int index)
{
  SettingsBlock *settings;
  SettingsEntry *entry;
  
  settings = FUN_00177d4c();
  if (0 <= index && (index < SETTINGS_ENTRY_COUNT)) {
    entry = &settings->entries[index];
  }
  else {
    entry = 0;
  }
  return entry;
}
