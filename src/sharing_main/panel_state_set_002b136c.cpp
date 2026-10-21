/* HSTMATCH module=hstp_trans_main.prx start=0x002b136c end=0x002b16c0 symbol=FUN_002b136c lang=c++ */
/* Clone of src/eboot/panel_state_set_002a1f60.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: switch on a local copy of the new state with cases 0,1,2 in source order [tests come out 2,1,0], the case-0 virtual call is m1(1) because a1 already holds 1 from the previous compare, the lerp re-reads the rectangle field through a char* view so it is not CSE'd, the two Vec4 args are declared b then a); names and types await human review. */
struct Rect {
  short s0, s2;
  short x4, y6, x8, y10;
};
struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));
struct Child {
  virtual void m0();
  virtual void m1(int v);
};
struct Bar {
  char pad0[0x20];
  float f20;
  char pad1[0x60 - 0x24];
  float f60;
};
struct Glob {
  char pad0[0xc];
  int f0c;
  char pad1[0x52 - 0x10];
  unsigned char b52;
};
struct Obj {
  int state;
  int prev;
  int f8;
  Child *c0c;
  Child *c10;
  Child *c14;
  Child *c18;
  void *w1c;
  void *w20;
  void *w24;
  Rect *r28;
  Rect *r2c;
  int pad30;
  short s34;
  short s36;
  float f38;
};

extern "C" {
extern Glob *DAT_003daec4;
void FUN_00105470(void *, int);
void FUN_00108558(void *);
void FUN_0006433c(Glob *, float);
void FUN_000646f4(Glob *, Vec4 *, Vec4 *, int, int, int, float, float);
}

extern "C" void FUN_002b136c(Obj *self, int ns)
{
  self->prev = self->state;
  self->state = ns;
  self->f8 = 0;
  int st = self->state;
  switch (st) {
  case 0:
    self->c0c->m1(1);
    {
      Glob *g = DAT_003daec4;
      g->f0c = 0;
      g->b52 = 0;
    }
    break;
  case 1:
    if (self->prev != 1) {
      if (self->prev == 0) {
        ((Bar *)self->c0c)->f60 = 120.0f;
        FUN_00108558(self->c0c);
      }
      self->c0c->m1(0);
      self->c10->m1(0);
      self->c14->m1(1);
      self->c18->m1(1);
      FUN_00105470(self->w1c, 0);
      FUN_00105470(self->w20, 1);
      FUN_00105470(self->w24, 1);
      FUN_00105470(self->r28, 1);
      Glob *g = DAT_003daec4;
      g->f0c = 0;
      g->b52 = 0;
    }
    break;
  case 2: {
    self->f38 = 0;
    self->s34 = (self->r2c->x4 + self->r2c->x8) / 2;
    self->s36 = (self->r2c->y6 + self->r2c->y10) / 2;
    Rect *r = self->r28;
    float t = self->f38;
    short mx = (r->x4 + r->x8) / 2;
    r->x4 = (short)(int)((float)mx + t * (float)(*(short *)((char *)r + 4) - mx));
    r->x8 = (short)(int)((float)mx + t * (float)(*(short *)((char *)r + 8) - mx));
    short my = (r->y6 + r->y10) / 2;
    r->y6 = (short)(int)((float)my + t * (float)(*(short *)((char *)r + 6) - my));
    r->y10 = (short)(int)((float)my + t * (float)(*(short *)((char *)r + 10) - my));
    self->c0c->m1(0);
    self->c10->m1(1);
    self->c14->m1(1);
    self->c18->m1(1);
    FUN_00105470(self->w1c, 1);
    FUN_00105470(self->w20, 1);
    FUN_00105470(self->w24, 1);
    FUN_0006433c(DAT_003daec4, 1.0f + ((Bar *)self->c0c)->f20);
    Vec4 b;
    Vec4 a;
    a.w = 0.75f;
    a.x = 0;
    a.y = 0;
    a.z = 0;
    b.x = 0;
    b.y = 0;
    b.z = 0;
    b.w = 0;
    FUN_000646f4(DAT_003daec4, &b, &a, 5, 0, 0, 65534.0f, -1.0f);
    break;
  }
  }
}
