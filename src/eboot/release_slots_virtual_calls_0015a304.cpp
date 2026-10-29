/* HSTMATCH module=EBOOT.BIN start=0x0015a304 end=0x0015a3cc symbol=FUN_0015a304 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: byte flag unsigned char (lbu), the two indirect calls written as C++ virtual calls (slot 3), loop index declared before the walking pointer for the s-registers; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/panel_host.h"

extern "C" void FUN_0015a3cc(...);

/* The two owned widgets; slot 3 releases their resources. */
struct Widget {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
};

/* Release the widgets and hand each slot object back, unless the panel is in one of the busy states. */
extern "C" void FUN_0015a304(PanelHost *self)
{
  Widget *widget;
  int i;
  PanelHost *cursor;
  
  if ((self->unk1c == 0) ||
     ((self->unk18 == 0 && self->state != 8 && self->state != 3))) {
    if (self->widgetA != 0) {
      ((Widget *)self->widgetA)->v3();
    }
    widget = (Widget *)self->widgetB;
    if (widget != 0) {
      widget->v3();
    }
    i = 0;
    cursor = self;
    do {
      if (cursor->slot[0] != 0) {
        FUN_0015a3cc(self,cursor->slot[0],i);
      }
      i = i + 1;
      cursor = (PanelHost *)((char *)cursor + sizeof(void *));
    } while (i < PANEL_HOST_SLOTS);
  }
}
