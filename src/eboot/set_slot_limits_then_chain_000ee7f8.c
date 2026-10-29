/* HSTMATCH module=EBOOT.BIN start=0x000ee7f8 end=0x000ee860 symbol=FUN_000ee7f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: FUN_001036f8 call regained its dropped second argument (0); readability pass; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_000ee890(ReplayPane *);
extern void FUN_00103480(ReplayPane *);
extern void FUN_001036f8(ReplayPane *, int);

/* While the replay pane is shown, pushes layers 0-3 to the offsets (-24, +24, -24, +24),
   then hides the pane. */
void FUN_000ee7f8(ReplayPane *pane)
{
  PaneLayer *layer1;
  PaneLayer *layer2;
  PaneLayer *layer3;

  if (pane->base.shown != 0) {
    layer1 = pane->layer[1];
    layer2 = pane->layer[2];
    layer3 = pane->layer[3];
    pane->layer[0]->offset = -24.0f;
    layer1->offset = 24.0f;
    layer2->offset = -24.0f;
    layer3->offset = 24.0f;
    FUN_00103480(pane);
  }
  FUN_000ee890(pane);
  FUN_001036f8(pane, 0);
}
