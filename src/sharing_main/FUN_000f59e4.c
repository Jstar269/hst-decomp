/* HSTMATCH module=hstp_trans_main.prx start=0x000f59e4 end=0x000f5a18 symbol=FUN_000f59e4 lang=c99 */
/* Clone of src/eboot/FUN_000f031c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/ingame_panes.h"

extern void FUN_00108f54();

/* Show the fade-cycle pane with its fade level at zero. */
void FUN_000f59e4(FadeCyclePane *self)
{
  FUN_00108f54(self,1);
  self->base.shown = 1;
  self->scale = 0.0f;
}
