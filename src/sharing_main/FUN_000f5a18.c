/* HSTMATCH module=hstp_trans_main.prx start=0x000f5a18 end=0x000f5a4c symbol=FUN_000f5a18 lang=c99 */
/* Clone of src/eboot/FUN_000f0350.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/ingame_panes.h"

extern void FUN_00108f54();

/* Hide the fade-cycle pane with its fade level at one. */
void FUN_000f5a18(FadeCyclePane *self)
{
  FUN_00108f54(self,0);
  self->base.shown = 0;
  self->scale = 1.0f;
}
