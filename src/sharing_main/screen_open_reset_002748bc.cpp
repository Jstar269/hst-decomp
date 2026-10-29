/* HSTMATCH module=hstp_trans_main.prx start=0x002748bc end=0x00274b9c symbol=FUN_002748bc lang=c++ */
/* Hand-written reconstruction (port of src/eboot/screen_open_reset_00263a40.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Screen (re)open handler: hides the helper widget (virtual slots 10 and 11), shows the pane widgets through virtual slot 1 depending on the flag at +0x644, updates the highlight state of the panel at +0x640 from the environment object's flag (with the special-case byte store for modes 0x3f..0x42 + 0x43) and resets the camera helpers. The panel mode switch has no default (retail's miss path jumps to the shared store, not through a goto). Names provisional. */
#include "hst/screen_obj.h"

struct Widget {
  virtual void v0();
  virtual void v1(int);
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
  virtual void v10();
  virtual void v11();
};
extern "C" {
extern int DAT_003751d4;
extern ScreenEnv *DAT_003e1e04;
extern unsigned DAT_003f39ac;
extern int DAT_003f39b0;
extern int DAT_003e1a08;
extern char DAT_003eaad8[];
void FUN_0001d970(int);
void FUN_00108f54(void *, int);
void FUN_00108e6c(float, void *);
void FUN_001090f4(void *, int);
void FUN_00105470(int, int);
void FUN_00274e08(void *, int);
void FUN_00291b78(void *, int, int);
void FUN_00292bf8(void *);
void *FUN_0008f170(int);
void FUN_001c1f44(void *, int);

/* Screen (re)open handler (see the description above). */
void FUN_002748bc(ScreenObj *self)
{
  FUN_0001d970(DAT_003751d4);
  if (self->part != 0) {
    ((Widget *)self->part)->v10();
    ((Widget *)self->part)->v11();
  }
  self->unk54 = 1;
  self->unk55 = 0;
  FUN_00108f54(self, 0);
  FUN_00108e6c(1000.0f, self);
  FUN_001090f4(self, 16);
  self->unk658->v1(1);
  if (self->unk644 != 0) {
    self->unk66c->v1(1);
    self->unk67c->v1(1);
  } else {
    self->unk65c->v1(1);
  }
  self->unk680->v1(1);
  ScreenPanel *open_panel = self->panel;
  int unk78 = open_panel->unk78;
  int unk74 = open_panel->unk74;
  if (unk74 != 0 || unk78 != 0) {
    FUN_00105470(self->unk6e0, 0);
    FUN_00105470(self->unk6d8, 0);
    FUN_00105470(self->unk6dc, 0);
  }
  FUN_00105470((int)self->item, 1);
  self->item->unk24 = self->item->unk28 + 1;
  FUN_00274e08(self, 0);
  bool enabled = true;
  if (DAT_003e1e04 != 0 && DAT_003e1e04->unk178 == 0) enabled = false;
  if (DAT_003f39ac - 0x3f < 4 && DAT_003f39b0 == 0x43) {
    if (DAT_003e1e04 != 0 && DAT_003e1e04->unk28 == 0xb) self->panel->unk2c02 = 1;
  } else {
    if (enabled) {
      FUN_00291b78(self->panel, 1, 1);
    } else {
      FUN_00291b78(self->panel, 0, 1);
    }
    ScreenPanel *p = self->panel;
    if (p->unk5c == 0) {
      p->unk61c = !enabled;
    } else {
      switch (p->unk80) {
        case 3:
          if (enabled) p->unk61c = 0; else p->unk61c = 1;
          FUN_00292bf8(self->panel);
          break;
        case 2:
          if (enabled) p->unk61c = 0; else p->unk61c = 2;
          FUN_00292bf8(self->panel);
          break;
      }
    }
    self->unk1e40 = 0;
  }
  FUN_00108f54(FUN_0008f170(DAT_003e1a08), 0);
  FUN_00108e6c(100000.0f, FUN_0008f170(DAT_003e1a08));
  FUN_001c1f44(DAT_003eaad8, 4);
  self->unk1e48 = 0;
}
}
