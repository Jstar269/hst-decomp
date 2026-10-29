/* HSTMATCH module=hstp_trans_main.prx start=0x000f5070 end=0x000f50a0 symbol=FUN_000f5070 lang=c99 */
/* Clone of src/eboot/FUN_000ee860.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00108f54(PaneBase *, int);

/* Shows the replay pane. */
void FUN_000f5070(PaneBase *pane)
{
  FUN_00108f54(pane,1);
  pane->shown = 1;
}
