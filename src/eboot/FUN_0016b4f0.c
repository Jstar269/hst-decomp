/* HSTMATCH module=EBOOT.BIN start=0x0016b4f0 end=0x0016b510 symbol=FUN_0016b4f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/settings_block.h"

extern SettingsBlock * FUN_0016bb88();

/* Returns the halfword setting at +0x103a. */
u16 FUN_0016b4f0(void)
{
  SettingsBlock *settings;
  
  settings = FUN_0016bb88();
  return settings->unk103a;
}
