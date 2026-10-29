/* HSTMATCH module=EBOOT.BIN start=0x00226030 end=0x002260e0 symbol=FUN_00226030 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: ordered saved locals and moved the empty-range exit ahead of cursor initialization; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_pane.h"

extern void FUN_00103628();
extern void FUN_0010b730();
extern void FUN_0010b76c();
extern void FUN_00224738();

/* Re-places every slot of the pane through the layout helper, then shows the pane. */
void FUN_00226030(SlotPaneScreen *screen)
{
  PaneSlotObj *pane;
  int i;
  
  pane = screen->ctx->pane;
  FUN_0010b730(pane->handle);
  pane->unk90 = 0;
  pane->unk118 = 0;
  i = 0;
  if (pane->count <= 0) goto done;
  do {
    FUN_0010b76c(pane->handle,(int)pane->xs[i],
                 (int)pane->ys[i],0,0,1);
    i = i + 1;
  } while (i < pane->count);
done:
  FUN_00103628(pane,0);
  pane->shown = 0;
  FUN_00224738(pane,pane->unk90);
}
