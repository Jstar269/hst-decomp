/* HSTMATCH module=EBOOT.BIN start=0x00278bd4 end=0x00278dc0 symbol=FUN_00278bd4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   matching idiom: the "q = self->f474" copy is written in both arms of the mode==3 test (it must stay a shared
   local), the count guard is spelled "<= 3" (a "< 4" test reuses the load register and loses retail's slti $at),
   the skipped-store path uses goto tail, and the mode chain is a descending ==-chain, not a switch. */
extern int *DAT_003386c8;

extern "C" int FUN_0008d994(int *);
extern "C" int FUN_0008d970(int *, int);
extern "C" int FUN_00049094(int);
extern "C" void FUN_0005f1e8(int, void *);

struct V {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
};

struct Obj {
  char pad0[0x3c];
  V f3c;
  char pad1[0x94 - 0x40];
  int f94;
  char pad2[0xac - 0x98];
  int fac;
  char pad3[0xb8 - 0xb0];
  int fb8;
  char pad4[0xc4 - 0xbc];
  int fc4;
  char pad5[0xf0 - 0xc8];
  int f0f0;
  int f0f4;
  unsigned char f0f8;
  char pad6[0xfc - 0xf9];
  V *ffc;
  V *f100;
  int f104;
  char pad7[0x190 - 0x108];
  int f190;
  char pad8[0x474 - 0x194];
  int f474;
  char pad9[0x8c5 - 0x478];
  unsigned char f8c5;
  char pad10[0xa0c - 0x8c6];
  V *fa0c;
  char pad11[0xa3c - 0xa10];
  V *fa3c;
};

extern "C" void FUN_00278bd4(Obj *self)
{
  V *p;
  int mode;
  int v;
  int q;
  int r;

  if (self->f104 == 6) {
    self->f100->v3();
    self->fa0c->v3();
    return;
  }
  self->fa3c->v3();
  ((V *)((char *)self + 0x3c))->v3();
  p = (V *)FUN_0008d994(DAT_003386c8);
  p->v3();
  mode = self->f104;
  if (mode == 4 || mode == 2 || mode == 1 || mode == 3 || mode == 7)
    v = self->f0f0;
  else
    goto tail;
  if (v != 0) {
    if (mode == 4 && self->f94 == 0)
      return;
    if (mode == 2 && self->fac == 0)
      return;
    if (mode == 1 && self->fb8 == 0)
      return;
    if (mode == 3) {
      if (self->fc4 == 0)
        return;
      q = self->f474;
    } else {
      q = self->f474;
    }
    if (*(int *)(q + 0xdc) <= 3)
      return;
    if (self->f8c5 == 0) {
      self->ffc->v3();
      return;
    }
    r = FUN_00049094(0);
    if (r != 0) {
      FUN_0005f1e8(self->f0f0, &self->f190);
      if (self->f0f8 != 0)
        FUN_0005f1e8(self->f0f4, &self->f190);
    } else {
      FUN_0005f1e8(FUN_0008d970(DAT_003386c8, 0), &self->f190);
    }
  }
tail:
  self->ffc->v3();
}
