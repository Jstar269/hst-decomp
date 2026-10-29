/* HSTMATCH module=EBOOT.BIN start=0x0015a01c end=0x0015a118 symbol=FUN_0015a01c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: loop index declared before the walking pointer (swaps the s-register pair); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/panel_host.h"

extern "C" {
extern u8 DAT_00309070;
extern u32 DAT_003403f8;
extern void FUN_00000a00(...);
}
/* The owned objects, each with its own virtual deleting destructor. */
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

/* Destructor: delete the two widgets and the slot objects, clear the global, free when delete_flag > 0. */
extern "C" PanelHost * FUN_0015a01c(PanelHost *self,short delete_flag)
{
  void *owned;
  int i;
  PanelHost *cursor;
  
  if (self != (PanelHost *)0x0) {
    self->vtable = &DAT_00309070;
    DAT_003403f8 = 0;
    owned = self->widgetA;
    if (owned != 0) {
      delete ((VC_0 *)(owned));
      self->widgetA = 0;
    }
    owned = self->widgetB;
    if (owned != 0) {
      delete ((VC_1 *)(owned));
      self->widgetB = 0;
    }
    i = 0;
    cursor = self;
    do {
      owned = cursor->slot[0];
      if (owned != 0) {
        delete ((VC_2 *)(owned));
        cursor->slot[0] = 0;
      }
      i = i + 1;
      cursor = (PanelHost *)((char *)cursor + sizeof(void *));
    } while (i < PANEL_HOST_SLOTS);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
