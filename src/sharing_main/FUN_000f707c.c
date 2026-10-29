/* HSTMATCH module=hstp_trans_main.prx start=0x000f707c end=0x000f70ac symbol=FUN_000f707c lang=c99 */
/* Clone of src/eboot/FUN_000f19b4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pane_shown.h"

extern void FUN_00108f54();

/* Shows the pane and records it in the flag. */
void FUN_000f707c(PaneShown78 *pane)
{
  FUN_00108f54(pane,1);
  pane->shown = 1;
}
