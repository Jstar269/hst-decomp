/* HSTMATCH module=hstp_trans_main.prx start=0x00233da4 end=0x00233dd4 symbol=FUN_00233da4 lang=c99 */
/* Clone of src/eboot/FUN_000ee860.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00108f54(PaneBase *, int);

/* Shows the replay pane. */
void FUN_00233da4(PaneBase *pane)
{
  FUN_00108f54(pane,1);
  pane->shown = 1;
}
