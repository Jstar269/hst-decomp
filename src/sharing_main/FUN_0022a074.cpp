/* HSTMATCH module=hstp_trans_main.prx start=0x0022a074 end=0x0022a0bc symbol=FUN_0022a074 lang=c++ */
/* Clone of src/eboot/FUN_0021ab00.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

/* Object with a virtual destructor. */
struct Deletable { virtual ~Deletable(); };

/* Deletes the menu through its virtual destructor and clears the pointer. */
extern "C" void FUN_0022a074(SelectionState *self)
{
  SelectionMenu *menu;
  
  menu = self->menu;
  if (menu != 0) {
    delete ((Deletable *)(menu));
    self->menu = 0;
  }
}
