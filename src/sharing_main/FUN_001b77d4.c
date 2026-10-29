/* HSTMATCH module=hstp_trans_main.prx start=0x001b77d4 end=0x001b7810 symbol=FUN_001b77d4 lang=c99 */
/* Clone of src/eboot/FUN_001aa208.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_select.h"
#include "hst/selection_panel.h"

extern u32 FUN_00177284();
extern SlotSelect * FUN_001aa91c();

/* Sets the item's sprite frame from the table lookup for the current unk2ec value. */
void FUN_001b77d4(SelectionPanel *panel)
{
  int offset;
  
  offset = FUN_00177284(FUN_001aa91c()->unk2ec);
  panel->items[3].spr->frame = panel->items[3].spr->baseFrame + offset;
}
