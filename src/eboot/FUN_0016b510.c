/* HSTMATCH module=EBOOT.BIN start=0x0016b510 end=0x0016b534 symbol=FUN_0016b510 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/settings_block.h"

extern SettingsBlock * FUN_0016bb88();

/* Returns whether the flag byte at +0x103c is set. */
bool FUN_0016b510(void)
{
  SettingsBlock *settings;
  
  settings = FUN_0016bb88();
  return settings->unk103c != '\0';
}
