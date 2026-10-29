/* HSTMATCH module=EBOOT.BIN start=0x0016b1bc end=0x0016b1dc symbol=FUN_0016b1bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsEntry * FUN_0016b270();

/* Returns the 16-bit id of entry `index` of the static entry table. */
int FUN_0016b1bc(int index)
{
  SettingsEntry *e;
  
  e = FUN_0016b270(index);
  return (int)e->unk2;
}
