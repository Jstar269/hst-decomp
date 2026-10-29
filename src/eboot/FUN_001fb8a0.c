/* HSTMATCH module=EBOOT.BIN start=0x001fb8a0 end=0x001fb8b0 symbol=FUN_001fb8a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slot_panel.h"

/* Increments the record counter. */
void FUN_001fb8a0(PanelRec *rec)
{
  rec->unke0 = rec->unke0 + 1;
}
