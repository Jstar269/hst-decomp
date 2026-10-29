/* HSTMATCH module=EBOOT.BIN start=0x00194e20 end=0x00194e34 symbol=FUN_00194e20 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/settings_block.h"

extern SettingsBlock * DAT_00341ccc;
extern void FUN_00194ba4();

/* Call FUN_00194ba4 with the object, the halfword setting at 0x1034 and the constant 0x20. */
void FUN_00194e20(u32 obj)
{
  FUN_00194ba4(obj,DAT_00341ccc->unk1034,0x20);
}
