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
  Entry *e0 = &self->e[0];
  Entry *e1 = &self->e[1];
  Entry *e2 = &self->e[2];
  Entry *e3 = &self->e[3];
  Entry *e4 = &self->e[4];
  int *pa = &self->f1d80;
  int *pb = &self->f1dbc;
  self->e[0].w->v1(0);
  FUN_0010f5d4(e0->w, t2);
  FUN_000ffb3c(*pa, 0);
  switch (FUN_001ef2d8(FUN_001ee200())) {
  case 5:
    ((int *)*pa)[9] = ((int *)*pa)[10];
    break;
  case 4:
    ((int *)*pa)[9] = ((int *)*pa)[10] + 1;
    break;
  case 3:
    ((int *)*pa)[9] = ((int *)*pa)[10] + 2;
    break;
  case 2:
    ((int *)*pa)[9] = ((int *)*pa)[10] + 3;
    break;
  case 1:
    ((int *)*pa)[9] = ((int *)*pa)[10] + 4;
    break;
  case 0:
    ((int *)*pa)[9] = ((int *)*pa)[10] + 5;
    break;
  }
  e1->w->v1(0);
  FUN_0010f5d4(e1->w, t1);
  e2->w->v1(0);
  FUN_0010f9d8(t3, e2->w, 0);
  FUN_000ffb3c(*pb, 0);
  int k = FUN_001ee200()->f10c8;
  int *p = (int *)*pb;
  p[9] = p[10] + k;
  e3->w->v1(0);
  FUN_0010f5d4(e3->w, t4);
  e4->w->v1(0);
  FUN_0010f5d4(e4->w, t5);
}
// sy1: 140/143 words (was 132/143, 131 differing words), everything but one pointer is retail's. Solved: the entry addresses
// e1..e4 and the two field pointers `int *pa = &self->f1d80; int *pb = &self->f1dbc;` are locals declared AFTER the five
// FUN_001ee200 reads (then the `addiu sN,s4,K` land inside the first virtual call's setup as in retail; declared before
// the reads they sit at the top); every switch body re-reads `*pa` (`((int*)*pa)[9] = ((int*)*pa)[10] + k`, retail `lw v1,0(s0)`
// per body) - the old `int *q = ...` before the switch is wrong; t1..t5 declaration order is irrelevant here.
// Open (3 words): retail materialises &self->e[0] (`addiu v0,s4,7712; sw v0,68(sp)`) and reloads it for the 2nd use
// (`lw v0,68(sp); lw a0,4(v0)`) while its 1st use is `lw a0,7716(s4)` direct; with `Entry *e0` used twice the pointer takes s8
// and t1 is spilled instead (121 differing words); used once it is folded into 7716(s4) and nothing is spilled (this file).
// near miss from lane sy1 (unreviewed)
