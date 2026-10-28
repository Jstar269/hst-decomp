/* HSTMATCH module=EBOOT.BIN start=0x001af80c end=0x001af8d8 symbol=FUN_001af80c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: declaration order (sets the saved registers), a pointer to the iVar1+0x360 block for the loop count reads, and the entry address grouped as (iVar4 + (iVar5 + 0x7bc)) + 9; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"
#include "hst/game_state.h"
extern "C" {
extern void FUN_000ffb3c(...);
extern void FUN_0010b980(...);
extern GameState *FUN_0019d474(...);
}
struct Widget { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001af80c(SlotMenuState *state)
{
  u32 row;
  u32 cursor;
  int offset;
  SlotTable *owner;
  ItemList *items;
  GameState *gs;
  u32 *rowp;
  u32 count;
  owner = state->owner;
  gs = FUN_0019d474();
  cursor = gs->cursor;
  ((Widget *)owner->widget)->m(0);
  FUN_0010b980(owner->widget,cursor,0);
  gs = FUN_0019d474();
  items = &gs->items;
  row = 0;
  if (gs->items.count != 0) {
    offset = 0;
    do {
      rowp = (u32 *)((int)owner + (offset + 0x7bc)) + 9;
      if (cursor == row) {
        FUN_000ffb3c(*rowp,0);
        count = items->count;
      }
      else {
        FUN_000ffb3c(*rowp,1);
        count = items->count;
      }
      row = row + 1;
      offset = offset + sizeof(MenuEntry);
    } while (row < count);
  }
}
