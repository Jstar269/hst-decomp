/* HSTMATCH module=EBOOT.BIN start=0x00263a40 end=0x00263d20 symbol=FUN_00263a40 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
extern int DAT_002cfc8c;
extern ScreenEnv *DAT_00338ac4;
extern unsigned DAT_0034a67c;
extern int DAT_0034a680;
extern int DAT_003386c8;
extern char DAT_0034179c[];
void FUN_0001dd24(int);
void FUN_00103628(void *, int);
void FUN_00103540(float, void *);
void FUN_001037c8(void *, int);
void FUN_000ffb3c(int, int);
void FUN_00263f8c(void *, int);
void FUN_00280830(void *, int, int);
void FUN_002817e0(void *);
void *FUN_0008d994(int);
void FUN_001b3ce8(void *, int);

/* Screen (re)open handler (see the description above). */
void FUN_00263a40(ScreenObj *self)
{
  FUN_0001dd24(DAT_002cfc8c);
  if (self->part != 0) {
    ((Widget *)self->part)->v10();
    ((Widget *)self->part)->v11();
  }
  self->unk54 = 1;
  self->unk55 = 0;
  FUN_00103628(self, 0);
  FUN_00103540(1000.0f, self);
  FUN_001037c8(self, 16);
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
    FUN_000ffb3c(self->unk6e0, 0);
    FUN_000ffb3c(self->unk6d8, 0);
    FUN_000ffb3c(self->unk6dc, 0);
  }
  FUN_000ffb3c((int)self->item, 1);
  self->item->unk24 = self->item->unk28 + 1;
  FUN_00263f8c(self, 0);
  bool enabled = true;
  if (DAT_00338ac4 != 0 && DAT_00338ac4->unk178 == 0) enabled = false;
  if (DAT_0034a67c - 0x3f < 4 && DAT_0034a680 == 0x43) {
    if (DAT_00338ac4 != 0 && DAT_00338ac4->unk28 == 0xb) self->panel->unk2c02 = 1;
  } else {
    if (enabled) {
      FUN_00280830(self->panel, 1, 1);
    } else {
      FUN_00280830(self->panel, 0, 1);
    }
    ScreenPanel *p = self->panel;
    if (p->unk5c == 0) {
      p->unk61c = !enabled;
    } else {
      switch (p->unk80) {
        case 3:
          if (enabled) p->unk61c = 0; else p->unk61c = 1;
          FUN_002817e0(self->panel);
          break;
        case 2:
          if (enabled) p->unk61c = 0; else p->unk61c = 2;
          FUN_002817e0(self->panel);
          break;
      }
    }
    self->unk1e40 = 0;
  }
  FUN_00103628(FUN_0008d994(DAT_003386c8), 0);
  FUN_00103540(100000.0f, FUN_0008d994(DAT_003386c8));
  FUN_001b3ce8(DAT_0034179c, 4);
  self->unk1e48 = 0;
}
}
