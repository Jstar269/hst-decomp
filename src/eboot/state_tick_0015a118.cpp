/* HSTMATCH module=EBOOT.BIN start=0x0015a118 end=0x0015a2b0 symbol=FUN_0015a118 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: rewritten with early returns, the 'state == 8 || (unsigned)(state - 3) <= 2' guard as one ||, the two arms swapped (unk1c != 0 && bits == 0 first) and the 2-bit field read as a signed bitfield; readability pass; exact match verified; names and types await human review. */
#include "hst/panel_host.h"
#include "hst/pad_state.h"

/* The two owned widgets; only slot 2 (per-frame update) is called. */
struct Widget {
  virtual void m0();
  virtual void m1();
  virtual void m2();
};

extern "C" {
extern PadState *DAT_002cfc8c;
extern char DAT_0034179c[];
void FUN_000ffb3c(void *, int);
void FUN_0015a2b0(PanelHost *, int);
void FUN_001b1c44(void *, int);
}

/* Per-frame update: tick the widgets and the countdown, then react to the confirm edge or the idle case. */
extern "C" void FUN_0015a118(PanelHost *self)
{
  if (self->widgetA != 0)
    ((Widget *)self->widgetA)->m2();
  if (self->widgetB != 0)
    ((Widget *)self->widgetB)->m2();
  if (self->countdown > 0) {
    self->countdown = self->countdown - 1;
    return;
  }
  if (self->state == 8 || (unsigned)(self->state - 3) <= 2)
    return;
  for (int i = 0; i < PANEL_HOST_NODES; i++) {
    if (self->node[i] != 0)
      FUN_000ffb3c(self->node[i], 0);
  }
  if (self->unk1c != 0 && DAT_002cfc8c->byte8b.st1 == 0) {
    FUN_001b1c44(DAT_0034179c, 3);
    FUN_0015a2b0(self, 8);
    for (int i = 0; i < PANEL_HOST_NODES; i++) {
      if (self->node[i] != 0)
        FUN_000ffb3c(self->node[i], 1);
    }
  } else {
    if (self->unk1c == 0 && self->unk18 == 0) {
      self->unk18 = 1;
      FUN_0015a2b0(self, 8);
      for (int i = 0; i < PANEL_HOST_NODES; i++) {
        if (self->node[i] != 0)
          FUN_000ffb3c(self->node[i], 1);
      }
    }
  }
}
