/* HSTMATCH module=hstp_trans_main.prx start=0x0022c014 end=0x0022c040 symbol=FUN_0022c014 lang=c99 */
/* Clone of src/eboot/FUN_000eecc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00108f54(PaneBase *, int);

/* Hides the Slot pane. */
void FUN_0022c014(PaneBase *pane)
{
  FUN_00108f54(pane,0);
  pane->shown = 0;
}
