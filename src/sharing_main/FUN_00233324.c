/* HSTMATCH module=hstp_trans_main.prx start=0x00233324 end=0x00233354 symbol=FUN_00233324 lang=c99 */
/* Clone of src/eboot/FUN_000ee860.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00108f54(PaneBase *, int);

/* Shows the replay pane. */
void FUN_00233324(PaneBase *pane)
{
  FUN_00108f54(pane,1);
  pane->shown = 1;
}
