/* HSTMATCH module=EBOOT.BIN start=0x0021ab00 end=0x0021ab48 symbol=FUN_0021ab00 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

/* Object with a virtual destructor. */
struct Deletable { virtual ~Deletable(); };

/* Deletes the menu through its virtual destructor and clears the pointer. */
extern "C" void FUN_0021ab00(SelectionState *self)
{
  SelectionMenu *menu;
  
  menu = self->menu;
  if (menu != 0) {
    delete ((Deletable *)(menu));
    self->menu = 0;
  }
}
