/* HSTMATCH module=EBOOT.BIN start=0x000ee890 end=0x000ee8d0 symbol=FUN_000ee890 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern "C" {
extern void FUN_00103628(PaneBase *, int);
}
/* Virtual view of a PaneLayer: slot 1 shows or hides it. */
struct LayerV { virtual void v0(); virtual void Show(int on); };

/* Hides the replay pane and shows its last layer. */
extern "C" void FUN_000ee890(ReplayPane *pane)
{
  FUN_00103628(&pane->base,0);
  pane->base.shown = 0;
  ((LayerV *)pane->layer[4])->Show(1);
}
