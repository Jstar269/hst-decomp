/* HSTMATCH module=EBOOT.BIN start=0x001aa1cc end=0x001aa208 symbol=FUN_001aa1cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_select.h"
#include "hst/selection_panel.h"

extern u32 FUN_0016b070();
extern SlotSelect * FUN_0019d474();

/* Sets the item's sprite frame from the table lookup for the current unk2e4 value. */
void FUN_001aa1cc(SelectionPanel *panel)
{
  int offset;
  
  offset = FUN_0016b070(FUN_0019d474()->unk2e4);
  panel->items[2].spr->frame = panel->items[2].spr->baseFrame + offset;
}
