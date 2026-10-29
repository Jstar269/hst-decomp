/* HSTMATCH module=hstp_trans_main.prx start=0x0022f8e4 end=0x0022f910 symbol=FUN_0022f8e4 lang=c99 */
/* Clone of src/eboot/FUN_000eecc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00108f54(PaneBase *, int);

/* Hides the Slot pane. */
void FUN_0022f8e4(PaneBase *pane)
{
  FUN_00108f54(pane,0);
  pane->shown = 0;
}
