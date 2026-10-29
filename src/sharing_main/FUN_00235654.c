/* HSTMATCH module=hstp_trans_main.prx start=0x00235654 end=0x0023568c symbol=FUN_00235654 lang=c99 */
/* Clone of src/eboot/FUN_002260e0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_pane.h"

extern void FUN_00108f54();

/* Marks the screen's pane as shown. */
void FUN_00235654(SlotPaneScreen *screen)
{
  PaneSlotObj *pane;
  
  pane = screen->ctx->pane;
  FUN_00108f54(pane,1);
  pane->shown = 1;
}
