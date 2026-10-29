/* HSTMATCH module=hstp_trans_main.prx start=0x00233114 end=0x00233178 symbol=FUN_00233114 lang=c99 */
/* Clone of src/eboot/FUN_00223ba0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/dual_entry_pane.h"

extern void FUN_00233324();

/* Shows the pane and clears both entries. */
void FUN_00233114(DualEntryPane *pane)
{
  FUN_00233324();
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
