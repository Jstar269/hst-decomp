/* HSTMATCH module=EBOOT.BIN start=0x001fb3f4 end=0x001fb404 symbol=FUN_001fb3f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slot_panel.h"

/* Increments the panel counter. */
void FUN_001fb3f4(SlotPanel *panel)
{
  panel->unk1034 = panel->unk1034 + 1;
}
