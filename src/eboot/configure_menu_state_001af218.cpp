/* HSTMATCH module=EBOOT.BIN start=0x001af218 end=0x001af30c symbol=FUN_001af218 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"
#include "hst/game_state.h"

extern "C" void FUN_000ffb3c(...);
extern "C" void FUN_0010b6d4(...);
extern "C" GameState *FUN_0019d474();
extern "C" void FUN_001acc30(...);
extern "C" void FUN_001acf64(...);
extern "C" void FUN_001ad350(...);
extern "C" void FUN_001ad604(...);
extern "C" void FUN_001ad89c(...);

/* MenuEntry.widget of a row, given an address 0x24 bytes before it. */
static inline int &RowWidget(int *p)
{
  return *(int *)((char *)p + 0x24);
}

extern "C" void FUN_001af218(SlotMenuState *state)
{
  SlotTable *owner;
  u32 row;
  int offset;
  ItemList *items;
  u32 *rowp;
  u32 count;
  u32 cursor;
  
  owner = state->owner;
  FUN_0010b6d4(owner->widget,6,8);
  cursor = FUN_0019d474()->cursor;
  items = &FUN_0019d474()->items;
  row = 0;
  if (items->count != 0) {
    offset = 0;
    do {
      rowp = (u32 *)((int)owner + (offset + 0x7bc));
      int &widget = RowWidget((int *)rowp);
      /* the highlighted row gets flag 0, every other row flag 1 */
      if (cursor == row) {
        FUN_000ffb3c(widget,0);
        count = items->count;
      }
      else {
        FUN_000ffb3c(widget,1);
        count = items->count;
      }
      row = row + 1;
      offset = offset + sizeof(MenuEntry);
    } while (row < count);
  }
  FUN_001acc30(owner,1);
  FUN_001acf64(owner,0);
  FUN_001ad350(owner,0);
  FUN_001ad604(owner,0);
  FUN_001ad89c(owner,0);
}
