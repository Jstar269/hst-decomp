/* HSTMATCH module=hstp_trans_main.prx start=0x002412cc end=0x00241314 symbol=FUN_002412cc lang=c++ */
/* Clone of src/eboot/FUN_0021ab00.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

/* Object with a virtual destructor. */
struct Deletable { virtual ~Deletable(); };

/* Deletes the menu through its virtual destructor and clears the pointer. */
extern "C" void FUN_002412cc(SelectionState *self)
{
  SelectionMenu *menu;
  
  menu = self->menu;
  if (menu != 0) {
    delete ((Deletable *)(menu));
    self->menu = 0;
  }
}
