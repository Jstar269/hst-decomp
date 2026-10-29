/* HSTMATCH module=EBOOT.BIN start=0x0021ab8c end=0x0021abe0 symbol=FUN_0021ab8c lang=c99 rodata=0x002c98c0 */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0r) corrected by hand: the item table is read as menu->item[menu->cursor], which emits the retail index-first address addition; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/selection_menu.h"

/* Item value of the selected slot while the state is one of the listed ones, otherwise -1. */
u32 FUN_0021ab8c(SelectionState *self)
{
  bool listed;
  u32 result;
  
  listed = false;
  switch(self->state) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 8:
  case 9:
  case 10:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
    listed = true;
  }
  if (listed) {
    result = self->menu->item[self->menu->cursor];
  }
  else {
    result = 0xffffffff;
  }
  return result;
}
