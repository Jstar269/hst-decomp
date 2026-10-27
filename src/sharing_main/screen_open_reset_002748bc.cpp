/* HSTMATCH module=hstp_trans_main.prx start=0x002748bc end=0x00274b9c symbol=FUN_002748bc lang=c++ */
/* Hand-written reconstruction (port of src/eboot/screen_open_reset_00263a40.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Screen (re)open handler: hides the helper widget (virtual slots 10 and 11), shows the pane widgets through virtual slot 1 depending on the flag at +0x644, updates the highlight state of the panel at +0x640 from the environment object's flag (with the special-case byte store for modes 0x3f..0x42 + 0x43) and resets the camera helpers. The panel mode switch has no default (retail's miss path jumps to the shared store, not through a goto). Names provisional. */
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
struct Item {
  char pad[0x24];
  int f24;
  int f28;
};
struct Panel {
  char pad0[0x5c];
  int f5c;
  char pad60[0x74 - 0x60];
  int f74;
  int f78;
  char pad7c[4];
  int f80;
  char pad84[0x61c - 0x84];
  int f61c;
  char pad620[0x2c02 - 0x620];
  unsigned char f2c02;
};
struct Env {
  char pad[0x28];
  int f28;
  char pad2c[0x178 - 0x2c];
  unsigned char f178;
};
struct Self {
  char pad0[0x54];
  unsigned char f54;
  unsigned char f55;
  Widget *f58;
  char pad5c[0x640 - 0x5c];
  Panel *f640;
  unsigned char f644;
  char pad645[0x658 - 0x645];
  Widget *f658;
  Widget *f65c;
  char pad660[0x66c - 0x660];
  Widget *f66c;
  char pad670[0x67c - 0x670];
  Widget *f67c;
  Widget *f680;
  char pad684[0x69c - 0x684];
  Item *f69c;
  char pad6a0[0x6d8 - 0x6a0];
  int f6d8;
  int f6dc;
  int f6e0;
  char pad6e4[0x1e40 - 0x6e4];
  unsigned char f1e40;
  char pad1e41[0x1e48 - 0x1e41];
  int f1e48;
};
extern "C" {
extern int DAT_003751d4;
extern Env *DAT_003e1e04;
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

void FUN_002748bc(Self *self)
{
  FUN_0001d970(DAT_003751d4);
  if (self->f58 != 0) {
    self->f58->v10();
    self->f58->v11();
  }
  self->f54 = 1;
  self->f55 = 0;
  FUN_00108f54(self, 0);
  FUN_00108e6c(1000.0f, self);
  FUN_001090f4(self, 16);
  self->f658->v1(1);
  if (self->f644 != 0) {
    self->f66c->v1(1);
    self->f67c->v1(1);
  } else {
    self->f65c->v1(1);
  }
  self->f680->v1(1);
  Panel *p0 = self->f640;
  int y = p0->f78;
  int x = p0->f74;
  if (x != 0 || y != 0) {
    FUN_00105470(self->f6e0, 0);
    FUN_00105470(self->f6d8, 0);
    FUN_00105470(self->f6dc, 0);
  }
  FUN_00105470((int)self->f69c, 1);
  self->f69c->f24 = self->f69c->f28 + 1;
  FUN_00274e08(self, 0);
  bool b = true;
  if (DAT_003e1e04 != 0 && DAT_003e1e04->f178 == 0) b = false;
  if (DAT_003f39ac - 0x3f < 4 && DAT_003f39b0 == 0x43) {
    if (DAT_003e1e04 != 0 && DAT_003e1e04->f28 == 0xb) self->f640->f2c02 = 1;
  } else {
    if (b) {
      FUN_00291b78(self->f640, 1, 1);
    } else {
      FUN_00291b78(self->f640, 0, 1);
    }
    Panel *p = self->f640;
    if (p->f5c == 0) {
      p->f61c = !b;
    } else {
      switch (p->f80) {
        case 3:
          if (b) p->f61c = 0; else p->f61c = 1;
          FUN_00292bf8(self->f640);
          break;
        case 2:
          if (b) p->f61c = 0; else p->f61c = 2;
          FUN_00292bf8(self->f640);
          break;
      }
    }
    self->f1e40 = 0;
  }
  FUN_00108f54(FUN_0008f170(DAT_003e1a08), 0);
  FUN_00108e6c(100000.0f, FUN_0008f170(DAT_003e1a08));
  FUN_001c1f44(DAT_003eaad8, 4);
  self->f1e48 = 0;
}
}
