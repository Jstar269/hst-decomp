/* HSTMATCH module=EBOOT.BIN start=0x001e5b64 end=0x001e5da0 symbol=FUN_001e5b64 lang=c++ rodata=0x002c8d0c */
struct W {
  virtual void v0();
  virtual void v1(int);
};

struct Entry {
  int a;
  W *w;
  int b;
};

struct Mgr {
  char pad0[0x108c];
  int f108c;
  float f1090;
  int f1094;
  int f1098;
  char pad1[8];
  int f10a4;
  char pad2[0x20];
  int f10c8;
};

struct Self {
  char pad0[0x1d80];
  int f1d80;
  char pad1[0x1dbc - 0x1d84];
  int f1dbc;
  char pad2[0x1e20 - 0x1dc0];
  Entry e[5];
};

extern "C" {
Mgr *FUN_001ee200();
int FUN_001ef2d8(Mgr *);
void FUN_0010f5d4(W *, int);
void FUN_0010f9d8(float, W *, int);
void FUN_000ffb3c(int, int);
}

extern "C" void FUN_001e5b64(Self *self)
{
  Mgr *m;
  int t1, t2, t4, t5;
  float t3;
  Entry *e0 = &self->e[0];
  Entry *e1 = &self->e[1];
  Entry *e2 = &self->e[2];
  Entry *e3 = &self->e[3];
  Entry *e4 = &self->e[4];

  m = FUN_001ee200();
  t1 = m->f108c;
  m = FUN_001ee200();
  t2 = m->f1094;
  m = FUN_001ee200();
  t3 = m->f1090;
  m = FUN_001ee200();
  t4 = m->f1098;
  m = FUN_001ee200();
  t5 = m->f10a4;
  e0->w->v1(0);
  FUN_0010f5d4(e0->w, t2);
  FUN_000ffb3c(self->f1d80, 0);
  int *q = (int *)self->f1d80;
  switch (FUN_001ef2d8(FUN_001ee200())) {
  case 5:
    q[9] = q[10];
    break;
  case 4:
    q[9] = q[10] + 1;
    break;
  case 3:
    q[9] = q[10] + 2;
    break;
  case 2:
    q[9] = q[10] + 3;
    break;
  case 1:
    q[9] = q[10] + 4;
    break;
  case 0:
    q[9] = q[10] + 5;
    break;
  }
  e1->w->v1(0);
  FUN_0010f5d4(e1->w, t1);
  e2->w->v1(0);
  FUN_0010f9d8(t3, e2->w, 0);
  FUN_000ffb3c(self->f1dbc, 0);
  int k = FUN_001ee200()->f10c8;
  int *p = (int *)self->f1dbc;
  p[9] = p[10] + k;
  e3->w->v1(0);
  FUN_0010f5d4(e3->w, t4);
  e4->w->v1(0);
  FUN_0010f5d4(e4->w, t5);
}
// NEAR MISS: 132/143 words (11 short), 131 differ. Structure identified: five 12-byte entries at
// self+0x1e20..0x1e54 with the widget pointer at +4; five Mgr fields saved (0x108c->s7, 0x1094->s8,
// 0x1090->f20 as float, 0x1098 and 0x10a4 spilled to sp+76/72); virtual call = vtable offset 12;
// FUN_0010f5d4(w,value), FUN_0010f9d8(float,w,0), FUN_000ffb3c(*(int*)(self+0x1d80),0), then
// *(int*)(*(int*)(self+0x1dbc)+0x24) = *(...+0x28) + Mgr->0x10c8; switch on
// FUN_001ef2d8(FUN_001ee200()) with bodies in source order 5,4,3,2,1,0 (jump table at 0x2c8d0c).
// What differs: retail computes all five entry addresses at entry into s3/s2/s1/s5 (+e0 spilled at
// sp+68) and colours self=s4, t1=s7, t2=s8, f1d80=s0, f1dbc=s6; ours gives self=s0 and shifts the
// rest, 11 words short overall. Ruled out: direct self->e[i].w indexing (frame 48, 118 words),
// declaring timer locals before/after the entry pointers, t2 before t1.
// near miss from lane fm4 (unreviewed)
