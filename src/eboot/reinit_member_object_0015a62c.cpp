/* HSTMATCH module=EBOOT.BIN start=0x0015a62c end=0x0015a728 symbol=FUN_0015a62c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: new-then-construct as `mem = alloc(); if (mem) mem = ctor(mem); m = mem;` (no zero-initialised temp), so the ctor result stays in v0 at the join; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/panel_host.h"

extern "C" {
extern u8 DAT_002de0ac;
extern char DAT_002de08c[];
extern char DAT_002de0b0[];
extern char DAT_002de0b8[];
extern int FUN_00000bcc(...);
extern void FUN_000ffb3c(...);
extern int FUN_001026b8(...);
extern u32 * FUN_00102e38(...);
extern int FUN_001039d8(...);
extern void FUN_00104118(...);
}
/* The owned widget has a virtual deleting destructor. */
struct VC_0 { virtual ~VC_0(); };

enum { WIDGET_SIZE = 0x54 };

/* Rebuild the first widget: delete the old one, construct a new one, load its layout and look up the two nodes. */
extern "C" void FUN_0015a62c(PanelHost *self)
{
  int mem;
  int widget;
  int node;
  void *old;
  
  old = self->widgetA;
  if ((old != 0) && (old != 0)) {
    delete ((VC_0 *)(old));
    self->widgetA = 0;
  }
  mem = FUN_00000bcc(WIDGET_SIZE);
  if (mem != 0) {
    mem = (int)(FUN_00102e38(mem));
  }
  widget = mem;
  self->widgetA = (void *)widget;
  FUN_00104118(widget,DAT_002de08c,0);
  mem = FUN_001039d8(self->widgetA,&DAT_002de0ac,0);
  if (mem != 0) {
    node = FUN_001026b8(mem,DAT_002de0b0);
    if (node != 0) {
      self->node[0] = (UiNode *)node;
      FUN_000ffb3c(node,1);
    }
    mem = FUN_001026b8(mem,DAT_002de0b8);
    if (mem != 0) {
      self->node[1] = (UiNode *)mem;
      FUN_000ffb3c(mem,1);
    }
  }
}
