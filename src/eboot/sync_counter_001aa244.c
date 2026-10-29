/* HSTMATCH module=EBOOT.BIN start=0x001aa244 end=0x001aa2a4 symbol=FUN_001aa244 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the switch value is read into a local before the pointer temporary is built (that order gives retail's a1/a0 register split); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_select.h"
#include "hst/selection_panel.h"

extern SlotSelect * FUN_0019d474();

/* Points the item's sprite at the frame for the current mode (base frame, or the one after it). */
void FUN_001aa244(SelectionPanel *panel)
{
  EntrySprite *sprite;
  EntryItem *item;
  int mode;

  mode = FUN_0019d474()->mode;
  item = &panel->items[4];
  switch (mode) {
    case 0:
      sprite = item->spr;
      sprite->frame = sprite->baseFrame;
      break;
    case 1:
      sprite = item->spr;
      sprite->frame = sprite->baseFrame + 1;
      break;
    default:
      break;
  }
}
