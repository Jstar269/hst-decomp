/* HSTMATCH module=hstp_trans_main.prx start=0x000f50a0 end=0x000f50cc symbol=FUN_000f50a0 lang=c99 */
/* Clone of src/eboot/FUN_000eecc4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00108f54(PaneBase *, int);

/* Hides the Slot pane. */
void FUN_000f50a0(PaneBase *pane)
{
  FUN_00108f54(pane,0);
  pane->shown = 0;
}
