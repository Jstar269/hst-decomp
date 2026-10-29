/* HSTMATCH module=EBOOT.BIN start=0x00223ba0 end=0x00223c04 symbol=FUN_00223ba0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/dual_entry_pane.h"

extern void FUN_00223db0();

/* Shows the pane and clears both entries. */
void FUN_00223ba0(DualEntryPane *pane)
{
  FUN_00223db0();
  pane->cur = DUAL_ENTRY_NONE;
  pane->key[0] = 0;
  pane->id[0] = 0;
  pane->unk8c[0] = 0;
  pane->unk94[0] = 0;
  pane->unk9c[0] = 0;
  pane->unka4[0] = 0;
  pane->unka6[0] = 0;
  pane->key[1] = 0;
  pane->id[1] = 0;
  pane->unk8c[1] = 0;
  pane->unk94[1] = 0;
  pane->unk9c[1] = 0;
  pane->unka4[1] = 0;
  pane->unka6[1] = 0;
}
