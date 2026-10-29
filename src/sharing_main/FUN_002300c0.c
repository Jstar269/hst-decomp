/* HSTMATCH module=hstp_trans_main.prx start=0x002300c0 end=0x002300f0 symbol=FUN_002300c0 lang=c99 */
/* Clone of src/eboot/FUN_000ee860.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00108f54(PaneBase *, int);

/* Shows the replay pane. */
void FUN_002300c0(PaneBase *pane)
{
  FUN_00108f54(pane,1);
  pane->shown = 1;
}
