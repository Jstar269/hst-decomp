/* HSTMATCH module=EBOOT.BIN start=0x0016b19c end=0x0016b1bc symbol=FUN_0016b19c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsEntry * FUN_0016b21c();

/* Returns the 16-bit id of entry `index` of the settings block. */
int FUN_0016b19c(int index)
{
  SettingsEntry *e;
  
  e = FUN_0016b21c(index);
  return (int)e->unk2;
}
