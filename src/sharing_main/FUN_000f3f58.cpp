/* HSTMATCH module=hstp_trans_main.prx start=0x000f3f58 end=0x000f3f98 symbol=FUN_000f3f58 lang=c++ */
/* Clone of src/eboot/FUN_000ee890.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern "C" {
extern void FUN_00108f54(PaneBase *, int);
}
/* Virtual view of a PaneLayer: slot 1 shows or hides it. */
struct LayerV { virtual void v0(); virtual void Show(int on); };

/* Hides the replay pane and shows its last layer. */
extern "C" void FUN_000f3f58(ReplayPane *pane)
{
  FUN_00108f54(&pane->base,0);
  pane->base.shown = 0;
  ((LayerV *)pane->layer[4])->Show(1);
}
