/* HSTMATCH module=hstp_trans_main.prx start=0x00233354 end=0x0023338c symbol=FUN_00233354 lang=c99 */
/* Clone of src/eboot/FUN_00223de0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/dual_entry_pane.h"

extern void FUN_00105470();
extern void FUN_00108f54();

/* Clears the shown flag and calls the layer helper with 1. */
void FUN_00233354(DualEntryPane *pane)
{
  FUN_00108f54(pane,0);
  pane->base.shown = 0;
  FUN_00105470(pane->layer,1);
}
