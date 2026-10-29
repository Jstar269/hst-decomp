/* HSTMATCH module=hstp_trans_main.prx start=0x001b7798 end=0x001b77d4 symbol=FUN_001b7798 lang=c99 */
/* Clone of src/eboot/FUN_001aa1cc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_select.h"
#include "hst/selection_panel.h"

extern u32 FUN_00177234();
extern SlotSelect * FUN_001aa91c();

/* Sets the item's sprite frame from the table lookup for the current unk2e4 value. */
void FUN_001b7798(SelectionPanel *panel)
{
  int offset;
  
  offset = FUN_00177234(FUN_001aa91c()->unk2e4);
  panel->items[2].spr->frame = panel->items[2].spr->baseFrame + offset;
}
